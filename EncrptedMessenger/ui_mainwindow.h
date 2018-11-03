/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextBrowser *recordBrowser;
    QPlainTextEdit *messageText;
    QPushButton *sendButton;
    QPushButton *fileButton;
    QPushButton *cameraButton;
    QPushButton *settingButton;
    QListWidget *listWidget;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QCheckBox *saveRecord;
    QPushButton *audioButton;
    QPushButton *editButton;
    QPushButton *disconectButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(702, 451);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        recordBrowser = new QTextBrowser(centralWidget);
        recordBrowser->setObjectName(QStringLiteral("recordBrowser"));
        recordBrowser->setGeometry(QRect(240, 10, 451, 261));
        messageText = new QPlainTextEdit(centralWidget);
        messageText->setObjectName(QStringLiteral("messageText"));
        messageText->setGeometry(QRect(240, 310, 451, 85));
        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(600, 400, 89, 24));
        fileButton = new QPushButton(centralWidget);
        fileButton->setObjectName(QStringLiteral("fileButton"));
        fileButton->setGeometry(QRect(240, 280, 21, 21));
        cameraButton = new QPushButton(centralWidget);
        cameraButton->setObjectName(QStringLiteral("cameraButton"));
        cameraButton->setGeometry(QRect(320, 280, 21, 21));
        settingButton = new QPushButton(centralWidget);
        settingButton->setObjectName(QStringLiteral("settingButton"));
        settingButton->setGeometry(QRect(670, 280, 21, 21));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 211, 351));
        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(10, 370, 21, 21));
        deleteButton = new QPushButton(centralWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(50, 370, 21, 21));
        saveRecord = new QCheckBox(centralWidget);
        saveRecord->setObjectName(QStringLiteral("saveRecord"));
        saveRecord->setGeometry(QRect(632, 280, 21, 21));
        audioButton = new QPushButton(centralWidget);
        audioButton->setObjectName(QStringLiteral("audioButton"));
        audioButton->setGeometry(QRect(280, 280, 21, 21));
        editButton = new QPushButton(centralWidget);
        editButton->setObjectName(QStringLiteral("editButton"));
        editButton->setGeometry(QRect(90, 370, 21, 21));
        disconectButton = new QPushButton(centralWidget);
        disconectButton->setObjectName(QStringLiteral("disconectButton"));
        disconectButton->setGeometry(QRect(200, 370, 21, 21));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "EncryptedMessenger", nullptr));
        sendButton->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        fileButton->setText(QString());
        cameraButton->setText(QString());
        settingButton->setText(QString());
        addButton->setText(QString());
        deleteButton->setText(QString());
        saveRecord->setText(QString());
        audioButton->setText(QString());
        editButton->setText(QString());
        disconectButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
