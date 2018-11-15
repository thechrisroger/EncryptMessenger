#include "filetransfer.h"
#include "ui_filetransfer.h"

#include <QDebug>
FileTransfer::FileTransfer(QWidget *parent, QString IP ) :
    QWidget(parent),
    ui(new Ui::FileTransfer)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowMaximizeButtonHint,false);
    this->setWindowIcon(QIcon("image/mainIcon.png"));
    this->setWindowTitle(tr("请选择要传输的文件"));
    ui->sendButton->setEnabled(false);
    ui->fileState->setText(tr("状态：未连接"));

    filesocket.connectToHost(IP,7778);
    connect(&filesocket,SIGNAL(connected()),this,SLOT(onConnected()));

    filePathName = QFileDialog::getOpenFileName();
    if(!filePathName.isEmpty())
    {
        QFileInfo fileInfo(filePathName);
        filePath = fileInfo.absolutePath();
        fileName = fileInfo.fileName();

        ui->sendButton->setEnabled(true);
        ui->pathLine->setText(filePath);
        ui->nameLine->setText(fileName);
    }

    this->show();

}

FileTransfer::~FileTransfer()
{
    delete ui;
}

void FileTransfer::on_selectButton_clicked()
{
    ui->sendButton->setEnabled(false);

    filePathName = QFileDialog::getOpenFileName();
    if(!filePathName.isEmpty())
    {
        qDebug() << "new file";
        QFileInfo fileInfo(filePathName);
        filePath = fileInfo.absolutePath();
        fileName = fileInfo.fileName();

        ui->sendButton->setEnabled(true);
        ui->pathLine->setText(filePath);
        ui->nameLine->setText(fileName);

    }
}

void FileTransfer::on_cancelButton_clicked()
{
    this->~FileTransfer();
}

void FileTransfer::on_sendButton_clicked()
{
    filesocket.write(fileName.toUtf8().data(),255);
    qDebug() << fileName;
    QFile file(filePathName);
    file.open(QIODevice::ReadOnly);
    while(!file.atEnd())
    {
        fileBuffer = file.readLine(1500);
        filesocket.write(fileBuffer);
    }

    qDebug() << "成功发送文件";

}

void FileTransfer::onConnected()
{
      ui->fileState->setText(tr("状态：已连接"));
}

