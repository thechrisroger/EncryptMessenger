#ifndef FILERECEIVE_H
#define FILERECEIVE_H

#include <QWidget>

#include <QByteArray>
#include <QString>
#include <QBuffer>
#include <QQueue>

#include <QFile>
#include <QFileInfo>
#include <QFileDialog>

#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class FileReceive;
}

class FileReceive : public QWidget
{
    Q_OBJECT

public:
    explicit FileReceive(QWidget *parent = 0);
    ~FileReceive();

private slots:
    void on_yesButton_clicked();

    void on_viewButton_clicked();

    void onNewConnection();

    void onReadyRead();
private:
    Ui::FileReceive *ui;

    QString filePath;
    QString fileName;
    QString filePathName;

    QByteArray fileBuffer;
    QBuffer buffer;

    QTcpServer fileServer;
    QTcpSocket *fileSocket;

};

#endif // FILERECEIVE_H
