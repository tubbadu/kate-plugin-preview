#pragma once

#include <KTextEditor/Document>
#include <KTextEditor/MainWindow>
#include <KTextEditor/Plugin>
#include <KTextEditor/View>
#include <KXMLGUIClient>

#include <QProcess>
#include <QTemporaryFile>
#include <QLabel>
#include <QWebEngineView>
#include <QDir>
#include <QHBoxLayout>
#include <QIcon>
#include <QDebug>
#include <QTextEdit>
#include <QFileInfo>

#include <KParts/Part>
#include <KParts/ReadOnlyPart>
#include <KPluginFactory>
#include <KPluginLoader>
#include <KAboutData>
#include <KLocalizedString>





// Forward declare
class KateLivePreviewPluginView;

class KateLivePreviewPlugin : public KTextEditor::Plugin
{
	Q_OBJECT
public:
	explicit KateLivePreviewPlugin(QObject *parent, const QList<QVariant> & = QList<QVariant>())
		: KTextEditor::Plugin(parent)
	{
	}


	QObject *createView(KTextEditor::MainWindow *mainWindow) override;
};

class KateLivePreviewPluginView : public QObject, public KXMLGUIClient
{
	Q_OBJECT
public:
	explicit KateLivePreviewPluginView(KateLivePreviewPlugin *plugin, KTextEditor::MainWindow *mainwindow);
	void onConversionFinished(int exitCode, QProcess::ExitStatus exitStatus);
	void onViewChanged(KTextEditor::View *v);
	void onDocumentSave(KTextEditor::Document *document, bool saveAs);
	void loadPreview(QString filename);
	void showMessage(QString text);
	void showMessage();
	void showPdf(QString);
	void showHtml(QString);
	bool elaborate(QString filename, QString doctype, bool forceReload);
	bool elaborateMarkdown(QString filename, QString doctype, bool forceReload);
	bool elaborateLatex(QString filename, QString doctype, bool forceReload);
	bool elaborateHtml(QString filename, QString doctype, bool forceReload);
	void startConversion(QString program, QStringList args);
	void conversionFinished(int exitCode, QProcess::ExitStatus exitStatus);
	
	
	

private:
	KTextEditor::MainWindow *m_mainWindow = nullptr;
	std::unique_ptr<QWidget> m_toolview;
	KParts::ReadOnlyPart *m_okularpart = nullptr;
	QWebEngineView *m_htmlviewer = nullptr;
	QProcess *m_converter = nullptr;
	QMap<QString, QFileInfo*> m_filenames;
	QSet<KTextEditor::Document*> m_connectedViews;
	QLabel *m_msg = nullptr;
	QFileInfo *m_tempfile = nullptr;
};
