#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "connect.h"
#include "friend.h"
#include "cipher.h"
#include "camera.h"

#include <QMainWindow>
#include <QInputDialog>
#include <QLabel>
#include <QLineEdit>
#include <QVector>
#include <QString>
#include <QListWidgetItem>
#include <QTcpServer>
#include <QTcpSocket>


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

    void onNewConnection();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_addButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::MainWindow *ui;
    QTcpServer *localServer;
    Connect *initiateConnect;
    Friend *newFriend;
    QString IP;
    qint32 port;

    QString *message;
    QByteArray *byteMessage;
    QVector<QString> *messageRecord;
    QVector<QString> *contactList;
    QLabel *statusLabel;
    QLineEdit *addEdit;
    QInputDialog addDialog;

};

#endif // MAINWINDOW_H
