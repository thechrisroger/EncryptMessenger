#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(tr("image/mainIcon.png")));
    this->setWindowFlag(Qt::WindowMaximizeButtonHint,false);
    statusLabel = new QLabel;
    ui->statusBar->addWidget(statusLabel);

    ui->addButton->setIcon(QIcon(tr("image/addIcon.png")));
    ui->deleteButton->setIcon(QIcon(tr("image/deleteIcon.png")));

    ui->editButton->hide();
    ui->disconectButton->hide();

    message = new QString;
    byteMessage = new QByteArray;
    messageRecord = new QVector<QString>;
    QString label("127.0.0.1:7777");
    ui->listWidget->addItem(label);

    localServer = new QTcpServer(this);
    connect(localServer,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
    localServer->listen(QHostAddress::Any,7777);

}

MainWindow::~MainWindow()
{
    delete statusLabel;
    delete message;
    delete messageRecord;
    delete ui;
}

void MainWindow::onNewConnection()
{
    newSocket = std::move(localServer->nextPendingConnection());
    QString newIP;
    newIP.append(newSocket->peerAddress().toString().begin()+7,newSocket->peerAddress().toString().length()-7);
    newFriend = new Friend(nullptr,newSocket,newIP);
}


void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    std::string address = item->text().toStdString();
    size_t addrLen = address.find(":");
    std::string portString(address,addrLen+1);
    address.erase(address.begin()+addrLen,address.end());

    QString ipTemp(address.data());
    IP = std::move(ipTemp);
    QString portTemp(portString.data());
    port = portTemp.toInt();
    initiateConnect  = new Connect(IP,port);
}

void MainWindow::on_addButton_clicked()
{
    QLineEdit::EchoMode echoMode = QLineEdit::Normal;
    bool ok = false;
    QString newAddress = QInputDialog::getText(this,tr(" "),tr("请输入新的IP"),echoMode,"127.0.0.1:7777",&ok);
    if(ok && !newAddress.isEmpty())
        ui->listWidget->addItem(newAddress);
}

void MainWindow::on_deleteButton_clicked()
{
    int row = ui->listWidget->currentRow();
    qDebug() << row;
    ui->listWidget->takeItem(row);
}
