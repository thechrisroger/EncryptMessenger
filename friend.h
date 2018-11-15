#ifndef FRIEND_H
#define FRIEND_H

#include "camera.h"

#include <QWidget>
#include <QLabel>
#include <QVector>
#include <QString>
#include <QCamera>
#include <QTcpSocket>
#include <QHostAddress>

namespace Ui {
class Friend;
}

class Friend : public QWidget
{
    Q_OBJECT

public:
    explicit Friend(QWidget *parent = 0,QTcpSocket *newSocket = 0);
    ~Friend();

private slots:
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);

    void onSocketReadReady();

    void on_sendButton_clicked();


    void on_saveRecord_stateChanged(int arg1);

private:
    Ui::Friend *ui;
    QTcpSocket *clientSocket;
    QString IP;
    qint32 port;

    bool saveFlag;
    QString message;
    QByteArray fileBuf;

    QByteArray *byteMessage;
    QVector<QString> *messageRecord;

};

#endif // FRIEND_H
