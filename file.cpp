#include "file.h"
#include "ui_file.h"

#include <QHostAddress>
File::File(QTcpSocket *socket) :
    ui(new Ui::File),
    fileSocket(socket)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("发送文件"));
    ui->sendButton->setEnabled(false);
    qDebug() << fileSocket->peerAddress().toString();

}

File::~File()
{
    delete ui;
}

void File::on_cancelButton_clicked()
{
    this->~File();
}

void File::on_sendButton_clicked()
{
    message = "FILE";
    fileSocket->write(message.toUtf8(),10);

    file = new QFile(filePathName);
    file->open(QIODevice::ReadOnly);
    message = file->readAll();
    fileSocket->write(message.toUtf8());
    this->~File();
}

void File::on_selectButton_clicked()
{
    QString path = QDir::currentPath();
    QString title = "请选择要发送的文件";
    QString filter = "所有文件(*.*)";
    filePathName = QFileDialog::getOpenFileName(this,title,path);
    if(!filePathName.isEmpty())
    {
        QFileInfo fileInfo(filePathName);
        QString fileName = fileInfo.fileName();
        QString filePath = fileInfo.filePath();

        ui->fileLineEdit->setText(fileName);
        ui->pathLineEdit->setText(filePath);
        ui->sendButton->setEnabled(true);
    }
}
