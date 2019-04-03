#include "send.h"
#include "ui_send.h"

Send::Send(QWidget *parent,QString IP) :
    QWidget(parent),
    ui(new Ui::Send),
    acceptFlag(false)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("传送文件"));
    this->setAttribute(Qt::WA_DeleteOnClose);
    ui->sendButton->setEnabled(false);

    fileSocket = new QTcpSocket;
    fileSocket->connectToHost(IP,7778);
    connect(fileSocket,SIGNAL(connected()),this,SLOT(onSocketConnected()));
    connect(fileSocket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));

    connect(this,SIGNAL(accpted()),this,SLOT(onRequestAccepted()));

    this->show();
}

Send::~Send()
{
    delete ui;
    delete fileSocket;
}

void Send::onSocketConnected()
{
    ui->stateLabel->setText(tr("已连接"));
    if(!getPathName.isEmpty())
    {
        ui->sendButton->setEnabled(true);
    }
}

void Send::onReadyRead()
{
    if(fileSocket->canReadLine())
    {
        qDebug() << "请求许可";
        qDebug() << fileSocket->readLine(256);
    }
    emit accpted();
}


void Send::on_selectButton_clicked()
{
    getPathName = QFileDialog::getOpenFileName(nullptr,tr("选择文件"),QDir::currentPath(),tr("(*.*)"));
    if(!getPathName.isEmpty())
    {
        QFileInfo fileInfo(getPathName);
        filePath = fileInfo.absolutePath();
        fileName = fileInfo.fileName();
        fileSize = std::move(fileInfo.size());

        ui->pathEdit->setText(filePath);
        ui->nameEdit->setText(fileName);
        if(fileSocket->state() == QAbstractSocket::ConnectedState)
        {
            ui->sendButton->setEnabled(true);
        }
    }

}

void Send::on_cancelButton_clicked()
{
    this->close();
}

void Send::on_sendButton_clicked()
{
    fileSocket->write(fileName.toUtf8().constData(),255);
    fileSocket->write(QByteArray::number(fileSize).constData(),255);
    qDebug() << fileSize;
    fileSocket->flush();

}

void Send::onRequestAccepted()
{
    qDebug() << "开始发送";
    QFile file(getPathName);
    file.open(QIODevice::ReadOnly);
    QByteArray byteline;
    while(!file.atEnd())
    {
        byteline =file.readLine();
        fileSocket->write(byteline);
    }
    fileSocket->flush();
    this->close();

}
