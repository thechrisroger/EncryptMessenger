#ifndef SEND_H
#define SEND_H

#include <QWidget>
#include <QTcpSocket>

#include <QByteArray>
#include <QString>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>

#include <QMessageBox>

namespace Ui {
class Send;
}

class Send : public QWidget
{
    Q_OBJECT

public:
    explicit Send(QWidget *parent = nullptr,QString IP = tr("127.0.0.1"));
    ~Send();

private:
    Ui::Send *ui;

    QTcpSocket *fileSocket;
    QByteArray buffer;
    bool acceptFlag;

    QString getPathName;
    QString filePath;
    QString fileName;
    qint64 fileSize;

signals:
    void accpted();

private slots:
    void onSocketConnected();

    void onReadyRead();

    void on_selectButton_clicked();

    void on_cancelButton_clicked();

    void on_sendButton_clicked();

    void onRequestAccepted();
};

#endif // SEND_H
