#ifndef RECEIVE_H
#define RECEIVE_H

#include <QWidget>

#include <QString>
#include <QTcpSocket>

#include <QFile>
#include <QFileInfo>
#include <QFileDialog>

#include <QBuffer>

namespace Ui {
class Receive;
}

class Receive : public QWidget
{
    Q_OBJECT

public:
    explicit Receive(QWidget *parent = nullptr, QTcpSocket *newSocket = nullptr);
    ~Receive();

private:
    Ui::Receive *ui;

    QTcpSocket *fileSocket;
    bool acceptFlag;
    bool createFlag;

    QString savePathName;
    QString savePath;
    QString saveName;
    qint64 fileSize;
    qint64 readSize;

    QFile *saveFile;

    QBuffer buffer;

private slots:

    void onReadyRead();


    void on_pushButton_clicked();
};


#endif // RECEIVE_H
