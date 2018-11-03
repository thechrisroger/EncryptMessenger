#ifndef FILE_H
#define FILE_H

#include <QWidget>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>

namespace Ui {
class File;
}

class File : public QWidget
{
    Q_OBJECT

public:
    explicit File(QWidget *parent = 0);
    ~File();

private slots:
    void on_cancelButton_clicked();

    void on_sendButton_clicked();

    void on_selectButton_clicked();

private:
    Ui::File *ui;
    QString filePathName;
    QString fileName;
};

#endif // FILE_H
