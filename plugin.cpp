#include "plugin.h"

#include <KLocalizedString>
#include <KPluginFactory>
#include <QHBoxLayout>
#include <QIcon>
#include <QDebug>
#include <QTextEdit>
#include <QCoreApplication>
#include <QFileInfo>

K_PLUGIN_FACTORY_WITH_JSON(MarkdownPandocPreviewPluginFactory, "plugin.json", registerPlugin<MarkdownPandocPreviewPlugin>();)

QObject *MarkdownPandocPreviewPlugin::createView(KTextEditor::MainWindow *mainWindow)
{
	return new MarkdownPandocPreviewPluginView(this, mainWindow);
}

MarkdownPandocPreviewPluginView::MarkdownPandocPreviewPluginView(MarkdownPandocPreviewPlugin *plugin, KTextEditor::MainWindow *mainwindow)
	: m_mainWindow(mainwindow)
{
	m_toolview.reset(m_mainWindow->createToolView(
		plugin, // pointer to plugin
		"markdownpreviewxxx", // just an identifier
		KTextEditor::MainWindow::Right, // we want to create a toolview on the right side
		QIcon::fromTheme("preview"),
		i18n("Markdown Preview xxx") // Name of the toolview
	));

	QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);

	connect(m_mainWindow, &KTextEditor::MainWindow::viewChanged, this, &MarkdownPandocPreviewPluginView::onViewChanged);
	m_msg = new QLabel(m_toolview.get());
	m_msg->setText("ciao");
	m_msg->setAlignment(Qt::AlignCenter);
	m_msg->hide();
	m_temp = new QTemporaryFile(QDir::tempPath() + "/kate.XXXXXX.html");
	//m_temp->open();
	m_converter = new QProcess();
	m_converter->setWorkingDirectory(QDir::tempPath());
	KPluginLoader loader("okularpart");
	if (KPluginFactory *factory = loader.factory()) {
		m_okularpart = factory->create<KParts::ReadOnlyPart>(m_toolview.get());
		if (m_okularpart) {
			//QString filePath = "/home/tubbadu/Polito/ESD/ESD_STM32/LAB11_DMA_and_Motor.pdf";
			//loadPreview(filePath);
		} else {
			qWarning() << "ERROR: okularpart not loaded correctly";
		}
	}
	m_htmlviewer = new QWebEngineView(m_toolview.get());

	connect(m_converter, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), [=](int exitCode, QProcess::ExitStatus exitStatus) {
		qWarning() << "Conversion end";
		if(exitStatus == QProcess::NormalExit && exitCode == 0){
			loadPreview(m_temp->fileName());
		} else {
			qWarning() << "ERROR: conversion command failed" << exitCode << exitStatus; // todo add gui error message
			showMessage("conversion failed");
		}
	});

	showMessage("Unsupported filetype");
}

void MarkdownPandocPreviewPluginView::onViewChanged(KTextEditor::View *v)
{
	if (!v || !v->document()) {
		return;
	}

	if(!m_connectedViews.contains(v->document())){ // check if already connected
		connect(v->document(), &KTextEditor::Document::documentSavedOrUploaded, this, &MarkdownPandocPreviewPluginView::onDocumentSave);
		m_connectedViews.insert(v->document());
	}

	QString filename = v->document()->url().toLocalFile();

	if (v->document()->highlightingMode().toLower() == "markdown" || true) {
		if(m_filenames.contains(filename)){
			loadPreview(m_filenames[filename]);
		} else {
			startConversion(filename, "m_temp->fileName()", v->document()->highlightingMode().toLower());
		}
	}
}

void MarkdownPandocPreviewPluginView::startConversion(QString filename, QString tempfilename, QString doctype){
	showMessage("Conversion started!");

	QString program;
	QStringList args;

	if(doctype == "markdown"){
		m_temp = new QTemporaryFile(QDir::tempPath() + "/kate.XXXXXX.html");
		m_temp->open();
		program = QString("pandoc");
		args = QStringList() << "--from=markdown" << "--to=html" << "--standalone" << "--pdf-engine=xelatex" << "-o" << m_temp->fileName() << filename;
	} else if(doctype == "latex"){
		m_temp = new QTemporaryFile(QDir::tempPath() + "/kate.XXXXXX.pdf");
		m_temp->open();
		program = QString("pdflatex");
		args = QStringList() << "--output-directory" << QDir::tempPath() << "--jobname" << QFileInfo(m_temp->fileName()).completeBaseName() << filename;
	} else {
		qWarning() << "ERROR: Unsupported doctype";
	}

	if(!m_temp->open()){
		qWarning() << "ERROR: temp file not correctly opened";
		return;
	}

	m_converter->terminate();
	m_converter->setProgram(program);
	m_converter->setArguments(args);
	m_converter->start();
	m_filenames.insert(filename, m_temp->fileName());
}

void MarkdownPandocPreviewPluginView::loadPreview(QString filename){
	if(filename.endsWith(".pdf")){
		m_okularpart->openUrl(QUrl::fromLocalFile(filename));
		showPdf();
	} else if (filename.endsWith(".html")){
		m_htmlviewer->setUrl(QUrl::fromLocalFile(filename));
		showHtml();
	} else {
		qWarning() << "ERROR: output file not correct:" << filename;
	}
}

void MarkdownPandocPreviewPluginView::showMessage(){
	m_okularpart->widget()->hide();
	m_htmlviewer->hide();
	m_msg->show();
}

void MarkdownPandocPreviewPluginView::showMessage(QString text){
	m_msg->setText(text);
	m_okularpart->widget()->hide();
	m_htmlviewer->hide();
	m_msg->show();
}

void MarkdownPandocPreviewPluginView::showHtml(){
	//m_okularpart->widget()->show();
	m_htmlviewer->show();
	m_msg->hide();
	qWarning()<< "done also this";
}

void MarkdownPandocPreviewPluginView::showPdf(){
	m_okularpart->widget()->show();
	//m_htmlviewer->show();
	m_msg->hide();
}

void MarkdownPandocPreviewPluginView::onDocumentSave(KTextEditor::Document *document, bool saveAs){
	QString filename = document->url().toLocalFile();
	startConversion(filename, m_filenames[filename], document->highlightingMode().toLower());
}


bool MarkdownPandocPreviewPluginView::elaborate(QString filename, QString doctype){
	if(doctype == "markdown"){
		return elaborateMarkdown(QString filename, QString doctype);
	} else if(doctype == "latex"){
		return elaborateLatex(QString filename, QString doctype);
	} else {
		qWarning() << "ERROR: Unsupported doctype";
	}
}

bool MarkdownPandocPreviewPluginView::elaborateMarkdown(QString filename, QString doctype, bool forceReload){
	// check if the temp file exists already
	QFileInfo tempfile;
	if(m_filenames.contains(filename)){
		tempfile= QFileInfo(m_filenames[filename]); // get previously used temp file info
	} else {
		m_temp = new QTemporaryFile(QDir::tempPath() + "/kate.XXXXXX.html"); // create new temp file
		if(!m_temp->open()){ // open temp file
			return false;
		}
		tempfile= QFileInfo(m_temp->fileName()); // get temp file info
	}

	if(forceReload || tempfile.size() < 1){
		program = QString("pandoc");
		args = QStringList() << "--from=markdown" << "--to=html" << "--standalone" << "--pdf-engine=xelatex" << "-o" << m_temp->fileName() << filename;
	} else {
		loadPreview(tempfile.fileName());
	}
	return true
}

bool MarkdownPandocPreviewPluginView::elaborateLatex(QString filename, QString doctype){

}

#include "plugin.moc"
