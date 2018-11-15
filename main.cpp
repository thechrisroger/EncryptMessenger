#include "mainwindow.h"
#include <QApplication>

#include "filereceive.h"
#include "filetransfer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    FileReceive f1;
    FileTransfer f2;

    return a.exec();
}
