#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "cipher.h"
#include "file.h"
#include "camera.h"

#include <QMainWindow>
#include <QLabel>
#include <QVector>
#include <QString>
#include <QListWidgetItem>
#include <QTcpServer>
#include <QTcpSocket>

#include <QFile>
#include <QFileInfo>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void connectToHost();

private slots:
    void onSocketConnected();

    void onSocketReadReady();

    void onNewConnection();

    void onSocketStateChanged();

    void on_sendButton_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_fileButton_clicked();

    void on_addButton_clicked();

    void on_cameraButton_clicked();

private:
    Ui::MainWindow *ui;
    QTcpServer *localServer;
    QTcpSocket *newSocket;
    QTcpSocket *clientSocket;
    bool connectedFlag;
    QString IP;
    qint32 port;
    QString *message;
    QByteArray *byteMessage;
    QVector<QString> *messageRecord;
    QVector<QString> *contactList;
    QLabel *newConnectionLabel;
    QLabel *statusLabel;
    Camera *camera;

};

#endif // MAINWINDOW_H
