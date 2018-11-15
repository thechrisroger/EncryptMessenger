#ifndef FILETRANSFER_H
#define FILETRANSFER_H

#include <QWidget>

#include <QByteArray>
#include <QString>

#include <QFile>
#include <QFileInfo>
#include <QFileDialog>

#include <QTcpSocket>

namespace Ui {
class FileTransfer;
}

class FileTransfer : public QWidget
{
    Q_OBJECT

public:
    FileTransfer(QWidget *parent = 0,QString IP = "127.0.0.1");
    ~FileTransfer();

private slots:
    void on_selectButton_clicked();

    void on_cancelButton_clicked();

    void on_sendButton_clicked();

    void onConnected();

private:
    Ui::FileTransfer *ui;

    QString filePath;
    QString fileName;
    QString filePathName;

    QByteArray fileBuffer;

    QTcpSocket filesocket;

};

#endif // FILETRANSFER_H
