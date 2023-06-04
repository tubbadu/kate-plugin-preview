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

#include <KParts/Part>
#include <KParts/ReadOnlyPart>
#include <KPluginFactory>
#include <KPluginLoader>
#include <KAboutData>
#include <KLocalizedString>




// Forward declare
class MarkdownPandocPreviewPluginView;

class MarkdownPandocPreviewPlugin : public KTextEditor::Plugin
{
    Q_OBJECT
public:
    explicit MarkdownPandocPreviewPlugin(QObject *parent, const QList<QVariant> & = QList<QVariant>())
        : KTextEditor::Plugin(parent)
    {
    }


    QObject *createView(KTextEditor::MainWindow *mainWindow) override;
};

class MarkdownPandocPreviewPluginView : public QObject, public KXMLGUIClient
{
    Q_OBJECT
public:
    explicit MarkdownPandocPreviewPluginView(MarkdownPandocPreviewPlugin *plugin, KTextEditor::MainWindow *mainwindow);
    void onConversionFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void startConversion(QString filename, QString tempfilename, QString doctype);
    void onViewChanged(KTextEditor::View *v);
    void onDocumentSave(KTextEditor::Document *document, bool saveAs);
    void loadPreview(QString filename);
    void showMessage(QString text);
    void showMessage();
    void showPdf();
    void showHtml();
    bool elaborate(QString filename, QString doctype);
    bool elaborateMarkdown(QString filename, QString doctype);
    bool elaborateLatex(QString filename, QString doctype);

private:
    KTextEditor::MainWindow *m_mainWindow = nullptr;
    std::unique_ptr<QWidget> m_toolview;
    KParts::ReadOnlyPart *m_okularpart = nullptr;
    QWebEngineView *m_htmlviewer = nullptr;
    QProcess *m_converter = nullptr;
    QTemporaryFile *m_temp = nullptr;
    QMap<QString, QString> m_filenames;
    QSet<KTextEditor::Document*> m_connectedViews;
    QLabel *m_msg = nullptr;
};
