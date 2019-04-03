#ifndef CONNECT_H
#define CONNECT_H

#include "send.h"
#include "receive.h"
#include "camera.h"
#include "data.h"

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QVector>
#include <QString>
#include <QTcpSocket>
#include <QTcpServer>

#include <QDateTime>

namespace Ui {
class Connect;
}

class Connect : public QWidget
{
    Q_OBJECT

public:
    explicit Connect(QString addrIP,qint16 addrPort);


private slots:
    void onWidgetClosed();

    void onSocketConnected();

    void onSocketReadReady();

    void onSocketStateChanged(QAbstractSocket::SocketState socketState);

    void onNewConnection();

    void on_sendButton_clicked();

    void on_saveRecord_stateChanged(int arg1);

    void on_cameraButton_clicked();

    void on_recordButton_clicked();

    void on_fileButton_clicked();

private:
    Ui::Connect *ui;

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

#endif // CONNECT_H
