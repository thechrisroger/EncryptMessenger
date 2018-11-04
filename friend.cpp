#include "friend.h"
#include "ui_friend.h"

#include <QDebug>
Friend::Friend(QWidget *parent ,QTcpSocket *newSocket):
    QWidget(parent),
    ui(new Ui::Friend),
    clientSocket(newSocket)
{
    ui->setupUi(this);
    IP.append(clientSocket->peerAddress().toString().begin()+7,clientSocket->peerAddress().toString().length()-7);
    this->setWindowTitle(IP);
    this->setWindowIcon(QIcon("image/mainIcon.png"));
    ui->settingButton->setIcon(QIcon("image/settingIcon.png"));

    byteMessage = new QByteArray;
    messageRecord = new QVector<QString>;
    connect(clientSocket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(onSocketStateChanged(QAbstractSocket::SocketState socketState)));
    connect(clientSocket,SIGNAL(readyRead()),this,SLOT(onSocketReadReady()));
    this->show();

}

Friend::~Friend()
{
    delete ui;
}

void Friend::onSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    switch (socketState) {
    case QAbstractSocket::ConnectedState:
        ui->stateLabel->setText(tr("已连接"));
        break;
    case QAbstractSocket::UnconnectedState:
         ui->stateLabel->setText(tr("未连接"));
    default:
        break;
    }
}

void Friend::onSocketReadReady()
{
    message = clientSocket->readLine();
    ui->recordBrowser->append(message);
}

void Friend::on_sendButton_clicked()
{
    message = ui->messageText->toPlainText().toUtf8();
    if(!message.isEmpty())
    {
        *byteMessage = message.toUtf8();
        clientSocket->write(byteMessage->constData(),byteMessage->length());
        ui->recordBrowser->append(message);
        messageRecord->push_back(message);
        ui->messageText->clear();
    }
}


