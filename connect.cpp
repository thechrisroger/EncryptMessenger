#include "connect.h"
#include "ui_connect.h"


Connect::Connect(QString addrIP, qint16 addrPort) :
    ui(new Ui::Connect),
    IP(addrIP),
    port(addrPort),
    saveFlag(true),
    recordData(addrIP)
{
    ui->setupUi(this);
    this->setWindowTitle(IP);
    this->setWindowFlag(Qt::WindowMaximizeButtonHint,false);
    this->setWindowIcon(QIcon(tr("image/mainIcon.png")));
    this->setAttribute(Qt::WA_DeleteOnClose);
    connect(this,SIGNAL(destroyed(QObject*)),this,SLOT(onWidgetClosed()));

    ui->settingButton->setIcon(QIcon(("image/settingIcon.png")));
    ui->fileButton->setIcon(QIcon(tr("image/fileIcon.png")));
    ui->cameraButton->setIcon(QIcon(tr("image/cameraIcon")));
    ui->recordButton->setIcon(QIcon(tr("image/recordIcon.png")));
    ui->sendButton->setEnabled(false);
    ui->saveRecord->setChecked(true);

    ui->settingButton->hide();
    ui->audioButton->hide();

    command = new QString;
    message = new QString;
    byteMessage = new QByteArray;
    messageRecord = new QVector<QString>;

    clientSocket = new QTcpSocket(this);
    clientSocket->connectToHost(IP.toUtf8().constData(),port);
    connect(clientSocket,SIGNAL(connected()),this,SLOT(onSocketConnected()));
    connect(clientSocket,SIGNAL(readyRead()),this,SLOT(onSocketReadReady()));

    connect(clientSocket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,SLOT(onSocketStateChanged(QAbstractSocket::SocketState)));

    fileServer = new QTcpServer(this);
    fileServer->listen(clientSocket->peerAddress(),7778);
    connect(fileServer,SIGNAL(newConnection()),this,SLOT(onNewConnection()));

    this->show();

}


void Connect::onWidgetClosed()
{
    auto w = new QWidget(nullptr);
    w->show();
    qDebug() << "111";
    clientSocket->disconnectFromHost();
    delete message;
    delete byteMessage;
    delete messageRecord;
    delete clientSocket;

    delete ui;
}

void Connect::onSocketConnected()
{
    ui->stateLabel->setText("已连接");
    ui->sendButton->setEnabled(true);
    peerIP.append(clientSocket->peerAddress().toString().cbegin(),
                  clientSocket->peerAddress().toString().length());
}

void Connect::onSocketReadReady()
{
    *message = clientSocket->readAll();

    ui->recordBrowser->append(peerIP +tr("      ") + QDateTime::currentDateTime().toString(tr("yyyy-MM-dd HH:mm:ss")));
    ui->recordBrowser->append(*message);
    if(saveFlag)
    {
        recordData.insertRecord(IP,QDateTime::currentDateTime().toString(tr("yyyy-MM-dd HH:mm:ss")),
                                *message);
    }
}

void Connect::onSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    qDebug() << "client changed";
    switch (socketState)
    {
    case QAbstractSocket::ConnectedState:
        ui->sendButton->setEnabled(true);
        break;
    case QAbstractSocket::ClosingState:
    case QAbstractSocket::UnconnectedState:
        ui->sendButton->setEnabled(false);
        break;
    }
}

void Connect::onNewConnection()
{
    recvFile = new Receive(this,fileServer->nextPendingConnection());
}


void Connect::on_sendButton_clicked()
{
    message->clear();
    message->append(ui->messageText->toPlainText());

    if(!message->isEmpty())
    {
        *byteMessage = message->toUtf8();

        clientSocket->write(byteMessage->constData(),byteMessage->length());

        ui->recordBrowser->append(tr("Local          ") + QDateTime::currentDateTime().toString(tr("yyyy-MM-dd HH:mm:ss")));
        ui->recordBrowser->append(*message);
        if(saveFlag)
        {
            recordData.insertRecord(IP,QDateTime::currentDateTime().toString(tr("yyyy-MM-dd HH:mm:ss")),
                                    *message);
        }
        ui->messageText->clear();
    }
}


void Connect::on_saveRecord_stateChanged(int arg1)
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

void Connect::on_cameraButton_clicked()
{
    camera = new Camera;
    camera->startCamera();
}


void Connect::on_recordButton_clicked()
{
    recordData.displayRecord();
}

void Connect::on_fileButton_clicked()
{
    sendFile = new Send(nullptr,IP);
}
