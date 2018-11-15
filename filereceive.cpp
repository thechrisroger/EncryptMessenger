#include "filereceive.h"
#include "ui_filereceive.h"

#include <QThread>

FileReceive::FileReceive(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileReceive)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowMaximizeButtonHint,false);
    this->setWindowTitle(tr("接收到了一个新文件"));
    this->setWindowIcon(QIcon("image/mainIcon"));

    fileServer.listen(QHostAddress::LocalHost,7778);
    connect(&fileServer,SIGNAL(newConnection()),this,SLOT(onNewConnection()));

    this->show();
}

FileReceive::~FileReceive()
{
    delete ui;
}

void FileReceive::on_yesButton_clicked()
{
    this->close();
}

void FileReceive::on_viewButton_clicked()
{

}

void FileReceive::onNewConnection()
{
    fileSocket = fileServer.nextPendingConnection();

    connect(fileSocket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
}

void FileReceive::onReadyRead()
{
    fileName = fileSocket->readLine(256);

    QQueue<QByteArray> que;
    while(fileSocket->canReadLine())
    {
        fileBuffer = fileSocket->readLine(1500);
        que.push_back(fileBuffer);
    }

    filePathName = QFileDialog::getSaveFileName();
    QFileInfo fileInfo(filePathName);
    filePath = fileInfo.absolutePath();
    fileName = fileInfo.fileName();
    ui->pathLine->setText(filePath);
    ui->nameLine->setText(fileName);

    QFile file(filePathName);
    file.open(QIODevice::ReadWrite);

    while(!que.isEmpty())
    {
        file.write(que.front());
        que.pop_front();
    }
    if(que.isEmpty())
        qDebug() << "成功接收文件！";
    file.close();
}
