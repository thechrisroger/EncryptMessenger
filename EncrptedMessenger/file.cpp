#include "file.h"
#include "ui_file.h"

File::File(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::File)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("发送文件"));
    ui->sendButton->setEnabled(false);
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
