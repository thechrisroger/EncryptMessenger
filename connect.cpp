#include "connect.h"
#include "ui_connect.h"

Connect::Connect(QString addrIP, qint32 addrPort) :
    ui(new Ui::Connect),
    IP(addrIP),port(addrPort)
{
    ui->setupUi(this);
    this->setWindowTitle(IP);
    this->setWindowIcon(QIcon("image/mainIcon.png"));
    ui->settingButton->setIcon(QIcon("image/settingIcon.png"));
    ui->sendButton->setEnabled(false);

    message = new QString;
    byteMessage = new QByteArray;
    messageRecord = new QVector<QString>;

    clientSocket = new QTcpSocket(this);
    clientSocket->connectToHost(IP.toUtf8().constData(),port);
    connect(clientSocket,SIGNAL(connected()),this,SLOT(onSocketConnected()));
    connect(clientSocket,SIGNAL(readyRead()),this,SLOT(onSocketReadReady()));

    this->show();
}

Connect::~Connect()
{
    delete ui;
}

void Connect::onSocketConnected()
{
    ui->stateLabel->setText("已连接");
    ui->sendButton->setEnabled(true);
}

void Connect::onSocketReadReady()
{
    *message = clientSocket->readAll();
    ui->recordBrowser->append(*message);
    messageRecord->push_back(*message);
}

void Connect::on_sendButton_clicked()
{
    *message = ui->messageText->toPlainText();
    if(!message->isEmpty())
    {
        *byteMessage = message->toUtf8();
        clientSocket->write(byteMessage->constData(),byteMessage->length());
        ui->recordBrowser->append(*message);
        messageRecord->push_back(*message);
        ui->messageText->clear();
    }
}

