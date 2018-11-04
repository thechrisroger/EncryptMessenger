#ifndef FILE_H
#define FILE_H

#include <QWidget>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QTcpSocket>



namespace Ui {
class File;
}

class File : public QWidget
{
    Q_OBJECT

public:
    explicit File(QTcpSocket *socket);
    ~File();

private slots:
    void on_cancelButton_clicked();

    void on_sendButton_clicked();

    void on_selectButton_clicked();

private:
    Ui::File *ui;
    QString filePathName;
    QString fileName;
    QTcpSocket *fileSocket;

    QString fileBuf;
    QString message;

    QFile *file;

};

#endif // FILE_H
