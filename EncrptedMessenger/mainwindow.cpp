#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    clientSocket(nullptr),
    connectedFlag(false)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("image/mainIcon.png"));
    ui->sendButton->setEnabled(false);
    statusLabel = new QLabel;
    ui->statusBar->addWidget(statusLabel);
    newConnectionLabel = new QLabel;
    ui->statusBar->addWidget(newConnectionLabel);

    ui->addButton->setIcon(QIcon("image/addIcon.png"));
    ui->deleteButton->setIcon(QIcon("image/deleteIcon.png"));
    ui->fileButton->setIcon(QIcon("image/fileIcon.png"));
    ui->cameraButton->setIcon(QIcon("image/cameraIcon.png"));
    ui->settingButton->setIcon(QIcon("image/settingIcon.png"));

    message = new QString;
    byteMessage = new QByteArray;
    messageRecord = new QVector<QString>;
    localServer = new QTcpServer;
    localServer->listen(QHostAddress::Any,9999);
    clientSocket = new QTcpSocket;

    QString  label("104.225.159.195:36089");
    ui->listWidget->addItem(label);
    label = "192.168.0.1:50000";
    ui->listWidget->addItem(label);
    label = "127.0.0.1:7777";
    ui->listWidget->addItem(label);

    connect(localServer,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
    connect(clientSocket,SIGNAL(connected()),this,SLOT(onSocketConnected()));
    connect(clientSocket,SIGNAL(readyRead()),this,SLOT(onSocketReadReady()));

}

MainWindow::~MainWindow()
{
    delete clientSocket;
    delete statusLabel;
    delete message;
    delete messageRecord;
    delete ui;
}

void MainWindow::onSocketConnected()
{
    ui->sendButton->setEnabled(true);
    connectedFlag = true;
    statusLabel->setText(("已连接"));
}

void MainWindow::onSocketReadReady()
{
    *message = clientSocket->readLine();
    ui->recordBrowser->append(*message);
    messageRecord->push_back(*message);
}

void MainWindow::onNewConnection()
{
    if(connectedFlag)
    {
        newConnectionLabel->setText(tr("您有一个新的连接请求"));
        *message = "新的连接请求";
        ui->recordBrowser->append(*message);
    }
    if(!connectedFlag)
    {
        newSocket = localServer->nextPendingConnection();
        connect(newSocket,SIGNAL(readyRead()),this,SLOT(onSocketReadReady()));
        connect(newSocket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(onSocketStateChanged()));
        //onSocketConnected();
    }
}

void MainWindow::onSocketStateChanged()
{

}

void MainWindow::on_sendButton_clicked()
{
    *message = ui->messageText->toPlainText();
    if(!message->isEmpty())
    {
        *byteMessage = message->toUtf8();
        clientSocket->write(byteMessage->constData(),byteMessage->length());
        qDebug() << *message;
        ui->recordBrowser->append(*message);
        messageRecord->push_back(*message);
        ui->messageText->clear();
    }
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    connectedFlag = false;
    if(clientSocket->state() == QAbstractSocket::ConnectingState)
    {
        clientSocket->abort();
        qDebug() << "abort connecting!";
    }
    else if(clientSocket->state() == QAbstractSocket::ConnectedState)
    {
        clientSocket->disconnectFromHost();
        qDebug() << "disconnected!";
    }
    ui->sendButton->setEnabled(false);
    statusLabel->setText((""));
    std::string address = item->text().toStdString();
    size_t addrLen = address.find(":");
    std::string portString(address,addrLen+1);
    address.erase(address.begin()+addrLen,address.end());

    QString ipTemp(address.data());
    IP = std::move(ipTemp);
    QString portTemp(portString.data());
    port = portTemp.toInt();
    qDebug() << IP;
    qDebug() << port;
    clientSocket->connectToHost(IP.toUtf8().constData(),port);
    qDebug() << "正在连接:" + IP ;

}


void MainWindow::on_fileButton_clicked()
{
    File *file = new File;
    file->show();
}

void MainWindow::on_addButton_clicked()
{

}

void MainWindow::on_cameraButton_clicked()
{
    camera = new Camera(this);
    qDebug() << "打开摄像头";
}
