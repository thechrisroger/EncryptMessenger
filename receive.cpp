#include "receive.h"
#include "ui_receive.h"

Receive::Receive(QWidget *parent, QTcpSocket *newSocket) :
    QWidget(nullptr),
    ui(new Ui::Receive),
    fileSocket(newSocket),
    acceptFlag(false),
    createFlag(true),
    readSize(0)
{
    Q_UNUSED(parent)
    ui->setupUi(this);
    this->setWindowTitle(tr("对方给您发送了一个文件"));

    connect(fileSocket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));

}

Receive::~Receive()
{
    delete ui;
}

void Receive::onReadyRead()
{

    if(acceptFlag)
    {
        QByteArray byteArray;
        while(readSize != fileSize)//动态分配不能文件不能写入，局部变量没有访问权限
        {
                byteArray = fileSocket->readLine();
                readSize += byteArray.length();
                qDebug() << readSize;
                saveFile->write(byteArray);
                saveFile->flush();
        }

//        while(fileSocket->canReadLine())
//        {byteArray = fileSocket->readLine();
//        buffer.write(byteArray);
//        readSize += byteArray.length();
//        qDebug() << readSize;}
        if(readSize >= fileSize)
        {
            qDebug() << "接收完毕";
            this->close();
        }
    }
    else
    {
        saveName = fileSocket->readLine(256);
        ui->nameEdit->setText(saveName);
        fileSize = fileSocket->readLine(256).toLongLong();
        qDebug() << saveName;
        if(!saveName.isEmpty())
        {
            this->show();
            acceptFlag = true;
        }
        buffer.open(QIODevice::WriteOnly);
    }

}

void Receive::on_pushButton_clicked()
{
    savePathName = QFileDialog::getSaveFileName(this,"保存文件",QDir::currentPath(),tr("(*.*)"));
    if(!savePathName.isEmpty())
    {
        saveFile = new QFile(savePathName);
        saveFile->open(QIODevice::WriteOnly);
        fileSocket->write("SURE_TO_RECEIVE",255);
    }

}
