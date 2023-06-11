#ifndef OKULARVIEWER_H
#define OKULARVIEWER_H





class OkularViewer : public QWidget
{
    Q_OBJECT
public:
    explicit OkularViewer(QWidget *parent = 0);
    Q_INVOKABLE bool getLineEditAndSplitter();
    Q_INVOKABLE void resize(const int &x, const int &y);
    Q_INVOKABLE void setText(const QString &text);
    Q_INVOKABLE bool arrowKeyPressed(QKeyEvent *event);


protected:
    bool eventFilter(QObject* watched, QEvent* event) override
    {
        //qWarning() << "eventFilter:" << watched << event;
        if (event->type() == QEvent::KeyPress) {
            qWarning() << "eventFilter:" << watched << event;
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            // Handle the key press event for the child widget
            /*if (keyEvent->key() == Qt::Key_Right || keyEvent->key() == Qt::Key_Left || keyEvent->key() == Qt::Key_Up || keyEvent->key() == Qt::Key_Down || keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return) {
                // Handle specific key press
                return arrowKeyPressed(keyEvent);
                return true; // Event handled
            }*/
            return arrowKeyPressed(keyEvent);
        }

        return m_lineEdit->eventFilter(watched, event);
    }



private:
	QLineEdit *m_lineEdit;
	QSplitter *m_splitter;
    QClipboard *m_clipboard;
};


#endif