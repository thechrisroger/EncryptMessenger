#ifndef NET_H
#define NET_H

#include <QObject>
#include <QString>
#include <QByteArray>
#include <QTcpSocket>
#include <QTcpServer>

class Net
{
public:
    Net();
    Net(qint32 port);
    ~Net();
    virtual void connectToHost() = 0;
    virtual void onNewSocketConnection() = 0;
    virtual void onSocketConnected() = 0;
    virtual void onSocketReadyRead() = 0;

private:
    QTcpServer *localServer;
    QTcpSocket *serverSocket;

    QTcpSocket *localSocket;

    QString *localIP;
    qint32 *localPort;

    QString *remoteIP;
    qint32 *remotePort;

    QString *newIP;
    qint32 *newPort;

};

#endif // NET_H
