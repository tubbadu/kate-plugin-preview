#include "plugin.h"

K_PLUGIN_FACTORY_WITH_JSON(KateLivePreviewPluginFactory, "plugin.json", registerPlugin<KateLivePreviewPlugin>();)

QObject *KateLivePreviewPlugin::createView(KTextEditor::MainWindow *mainWindow)
{
	return new KateLivePreviewPluginView(this, mainWindow);
}

KateLivePreviewPluginView::KateLivePreviewPluginView(KateLivePreviewPlugin *plugin, KTextEditor::MainWindow *mainwindow)
	: m_mainWindow(mainwindow)
{
	m_toolview.reset(m_mainWindow->createToolView(
		plugin, // pointer to plugin
		"katelivepreview", // just an identifier
		KTextEditor::MainWindow::Right, // we want to create a toolview on the right side
		QIcon::fromTheme("preview"),
		i18n("Kate Live Preview") // Name of the toolview
	));

	connect(m_mainWindow, &KTextEditor::MainWindow::viewChanged, this, &KateLivePreviewPluginView::onViewChanged);
	m_msg = new QLabel(m_toolview.get());
	m_msg->setText("ciao");
	m_msg->setAlignment(Qt::AlignCenter);
	m_msg->hide();

	m_converter = new QProcess();
	m_converter->setWorkingDirectory(QDir::tempPath());
	KPluginLoader loader("okularpart");
	if (KPluginFactory *factory = loader.factory()) {
		m_okularpart = factory->create<KParts::ReadOnlyPart>(m_toolview.get());
		if (!m_okularpart) {
			qWarning() << "ERROR: okularpart not loaded correctly";
		}
	}
	m_htmlviewer = new QWebEngineView(m_toolview.get());

	connect(m_converter, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), this, &KateLivePreviewPluginView::conversionFinished);

	showMessage("Unsupported filetype");
}

void KateLivePreviewPluginView::onViewChanged(KTextEditor::View *v)
{
	if (!v || !v->document()) {
		return;
	}

	if(!m_connectedViews.contains(v->document())){ // check if already connected
		connect(v->document(), &KTextEditor::Document::documentSavedOrUploaded, this, &KateLivePreviewPluginView::onDocumentSave);
		m_connectedViews.insert(v->document());
	}

	QString filename = v->document()->url().toLocalFile();
	QString doctype = v->document()->highlightingMode().toLower();

	elaborate(filename, doctype, false);
}

void KateLivePreviewPluginView::loadPreview(QString filename){
	if(filename.endsWith(".pdf")){
		showPdf(filename);
	} else if (filename.endsWith(".html") || filename.endsWith(".svg")){
		showHtml(filename);
	} else {
		qWarning() << "ERROR: output file not correct:" << filename;
	}
}

void KateLivePreviewPluginView::showMessage(){
	m_okularpart->widget()->hide();
	m_htmlviewer->hide();
	m_msg->show();
}

void KateLivePreviewPluginView::showMessage(QString text){
	m_msg->setText(text);
	showMessage();
}

void KateLivePreviewPluginView::showHtml(QString filename){
	qWarning() << filename;
	m_htmlviewer->setUrl(QUrl::fromLocalFile(filename));
	m_okularpart->widget()->hide();
	m_htmlviewer->show();
	m_msg->hide();
}

void KateLivePreviewPluginView::showPdf(QString filename){
	m_okularpart->openUrl(QUrl::fromLocalFile(filename));
	m_okularpart->widget()->show();
	m_htmlviewer->hide();
	m_msg->hide();
}

void KateLivePreviewPluginView::onDocumentSave(KTextEditor::Document *document, bool saveAs){
	QString filename = document->url().toLocalFile();
	//startConversion(filename, m_filenames[filename], document->highlightingMode().toLower());
	elaborate(filename, document->highlightingMode().toLower(), true);
}

void KateLivePreviewPluginView::startConversion(QString program, QStringList args){
	m_converter->terminate();
	m_converter->setProgram(program);
	m_converter->setArguments(args);
	m_converter->start();
}

void KateLivePreviewPluginView::conversionFinished(int exitCode, QProcess::ExitStatus exitStatus){
	qWarning() << "Conversion end";
	if(exitStatus == QProcess::NormalExit && exitCode == 0){
		loadPreview(m_tempfile->absoluteFilePath());
	} else {
		qWarning() << "ERROR: conversion command failed" << exitCode << exitStatus; // todo add gui error message
		showMessage("conversion failed");
	}
}


bool KateLivePreviewPluginView::elaborate(QString filename, QString doctype, bool forceReload){
	if(doctype == "markdown"){
		return elaborateMarkdown(filename, doctype, forceReload);
	} else if(doctype == "latex"){
		return elaborateLatex(filename, doctype, forceReload);
	} else if(doctype == "html" || doctype == "xml"){
		return elaborateHtml(filename, doctype, forceReload);
	} else {
		qWarning() << "ERROR: Unsupported doctype" << doctype;
	}
}

bool KateLivePreviewPluginView::elaborateMarkdown(QString filename, QString doctype, bool forceReload){
	// check if the temp file exists already
	if(m_filenames.contains(filename) && QFileInfo::exists(m_filenames[filename]->absoluteFilePath())){
		//qWarning() << filename << m_filenames[filename] << m_filenames[filename]->absoluteFilePath(); // << QFileInfo::exists(m_filenames[filename]->completeBaseName()) ;
		// TODO check if already exists
		m_tempfile = m_filenames[filename]; // get previously used temp file info
	} else {
		QTemporaryFile temp = QTemporaryFile(QDir::tempPath() + "/kate.XXXXXX.html"); // create new temp file
		if(!temp.open()){ // open temp file
			return false;
		}
		m_tempfile = new QFileInfo(temp.fileName()); // get temp file info
	}

	if(forceReload || m_tempfile->size() < 1){
		QString program = QString("pandoc");
		QStringList args = QStringList() << "--from=markdown" << "--to=html" << "--standalone" << "--pdf-engine=xelatex" << "-o" << m_tempfile->fileName() << filename;
		startConversion(program, args);
		m_filenames[filename] = m_tempfile;
	} else {
		loadPreview(m_tempfile->absoluteFilePath());
	}
	return true;
}

bool KateLivePreviewPluginView::elaborateLatex(QString filename, QString doctype, bool forceReload){
	// check if the temp file exists already
	if(m_filenames.contains(filename) && QFileInfo::exists(m_filenames[filename]->absoluteFilePath())){
		// TODO check if already exists
		m_tempfile = m_filenames[filename]; // get previously used temp file info
	} else {
		QTemporaryFile temp = QTemporaryFile(QDir::tempPath() + "/kate.XXXXXX.pdf"); // create new temp file
		if(!temp.open()){ // open temp file
			return false;
		}
		m_tempfile = new QFileInfo(temp.fileName()); // get temp file info
	}

	if(forceReload || m_tempfile->size() < 1){
		QString program = QString("pdflatex");
		QStringList args = QStringList() << "--output-directory" << m_tempfile->path() << "--jobname" << m_tempfile->completeBaseName() << filename;
		startConversion(program, args);
		m_filenames[filename] = m_tempfile;
	} else {
		loadPreview(m_tempfile->absoluteFilePath());
	}
	return true;
}

bool KateLivePreviewPluginView::elaborateHtml(QString filename, QString doctype, bool forceReload){
	// check if the temp file exists already
	if(!QFileInfo::exists(filename)){
		qWarning() << filename;
		return false;
	}
	loadPreview(filename);
	return true;
}







#include "plugin.moc"
