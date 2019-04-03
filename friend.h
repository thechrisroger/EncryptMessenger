#ifndef FRIEND_H
#define FRIEND_H

#include "send.h"
#include "receive.h"
#include "camera.h"
#include "data.h"

#include <QWidget>
#include <QLabel>
#include <QVector>
#include <QString>
#include <QCamera>

#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>

#include <QDateTime>

namespace Ui {
class Friend;
}

class Friend : public QWidget
{
    Q_OBJECT

public:
    explicit Friend(QWidget *parent = nullptr, QTcpSocket *newSocket = nullptr, QString newIP = tr("127.0.0.1"));

private slots:
    void onWidgetClosed();

    void onSocketStateChanged(QAbstractSocket::SocketState socketState);

    void onSocketReadReady();

    void on_sendButton_clicked();

    void on_saveRecord_stateChanged(int arg1);

    void on_recordButton_clicked();

    void on_cameraButton_clicked();

    void on_fileButton_clicked();

private:
    Ui::Friend *ui;

    QTcpSocket *clientSocket;
    QString IP;
    qint32 port;

    QString peerIP;

    bool saveFlag;
    QString *command;
    QString *message;

    QByteArray *byteMessage;
    QVector<QString> *messageRecord;

    Camera *camera;

    Data recordData;

    QTcpServer *fileServer;
    Send *sendFile;
    Receive *recvFile;


};

#endif // FRIEND_H
