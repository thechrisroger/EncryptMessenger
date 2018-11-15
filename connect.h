#ifndef CONNECT_H
#define CONNECT_H

#include <QWidget>
#include <QLabel>
#include <QVector>
#include <QString>
#include <QCamera>
#include <QTcpSocket>
#include <QHostAddress>

namespace Ui {
class Connect;
}

class Connect : public QWidget
{
    Q_OBJECT

public:
    explicit Connect(QString addrIP,qint32 addrPort);
    ~Connect();

private slots:
    void onSocketConnected();

    void onSocketReadReady();

    void on_sendButton_clicked();

    void on_saveRecord_stateChanged(int arg1);

private:
    Ui::Connect *ui;
    QTcpSocket *clientSocket;
    QString IP;
    qint32 port;

    bool saveFlag;
    QString *message;
    QByteArray *byteMessage;
    QVector<QString> *messageRecord;
};

#endif // CONNECT_H
