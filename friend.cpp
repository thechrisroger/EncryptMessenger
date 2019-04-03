#include "friend.h"
#include "ui_friend.h"

#include <QDebug>


Friend::Friend(QWidget *parent ,QTcpSocket *newSocket,QString newIP):
    QWidget(parent),
    ui(new Ui::Friend),
    clientSocket(newSocket),
    IP(newIP),
    saveFlag(true),
    recordData(IP)
{
    ui->setupUi(this);
    this->setWindowTitle(IP);
//    this->setWindowFlag(Qt::WindowMaximizeButtonHint,false);
    this->setWindowIcon(QIcon(tr("image/mainIcon.png")));
    this->setAttribute(Qt::WA_DeleteOnClose);
    connect(this,SIGNAL(destroyed(QObject*)),this,SLOT(onWidgetClosed()));

    ui->settingButton->setIcon(QIcon(tr("image/settingIcon.png")));
    ui->fileButton->setIcon(QIcon(tr("image/fileIcon")));
    ui->cameraButton->setIcon(QIcon(tr("image/cameraIcon")));
    ui->recordButton->setIcon(QIcon(tr("image/recordIcon")));
    ui->saveRecord->setChecked(true);

    ui->settingButton->hide();
    ui->audioButton->hide();

    message = new QString;
    byteMessage = new QByteArray;
    messageRecord = new QVector<QString>;


    connect(clientSocket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,SLOT(onSocketStateChanged(QAbstractSocket::SocketState)));
    onSocketStateChanged(QAbstractSocket::ConnectedState);
    connect(clientSocket,SIGNAL(readyRead()),this,SLOT(onSocketReadReady()));



    this->show();

}

void Friend::onWidgetClosed()
{
    clientSocket->disconnectFromHost();

    delete clientSocket;
    delete byteMessage;
    delete message;
    delete messageRecord;

    delete ui;
}


void Friend::onSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    switch (socketState)
    {
    case QAbstractSocket::ConnectedState:
        ui->stateLabel->setText(tr("已连接"));
        ui->sendButton->setEnabled(true);
        break;
    case QAbstractSocket::UnconnectedState:
         ui->stateLabel->setText(tr("未连接"));
         ui->sendButton->setEnabled(false);
        break;
    }
}

void Friend::onSocketReadReady()
{
    *message = clientSocket->readLine();

    ui->recordBrowser->append(IP +tr("      ") + QDateTime::currentDateTime().toString(tr("yyyy-MM-dd HH:mm:ss")));
    ui->recordBrowser->append(*message);
    if(saveFlag)
    {
        recordData.insertRecord(IP,QDateTime::currentDateTime().toString(tr("yyyy-MM-dd HH:mm:ss")),*message);
    }
}

void Friend::on_sendButton_clicked()
{
    *message = ui->messageText->toPlainText();
    if(!message->isEmpty())
    {
        *byteMessage = message->toUtf8();
        clientSocket->write(byteMessage->constData(),byteMessage->length());

        ui->recordBrowser->append(tr("Local          ") + QDateTime::currentDateTime().toString(tr("yyyy-MM-dd HH:mm:ss")));
        ui->recordBrowser->append(*message);
        if(saveFlag)
        {
            recordData.insertRecord(IP,QDateTime::currentDateTime().toString(tr("yyyy-MM-dd HH:mm:ss")),*message);
        }
        ui->messageText->clear();
    }
}


void Friend::on_saveRecord_stateChanged(int arg1)
{
    if(arg1 == 0)
    {
        saveFlag = false;
    }
    else if(arg1 == 2)
    {
        saveFlag = true;
    }
}


void Friend::on_recordButton_clicked()
{
    recordData.displayRecord();
}

void Friend::on_cameraButton_clicked()
{
    camera = new Camera;
    camera->startCamera();
}

void Friend::on_fileButton_clicked()
{
    sendFile = new Send(nullptr,IP);
}
