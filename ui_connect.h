/********************************************************************************
** Form generated from reading UI file 'connect.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECT_H
#define UI_CONNECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Connect
{
public:
    QTextBrowser *recordBrowser;
    QPlainTextEdit *messageText;
    QCheckBox *saveRecord;
    QPushButton *sendButton;
    QPushButton *settingButton;
    QLabel *stateLabel;
    QPushButton *audioButton;
    QPushButton *fileButton;
    QPushButton *cameraButton;
    QPushButton *recordButton;

    void setupUi(QWidget *Connect)
    {
        if (Connect->objectName().isEmpty())
            Connect->setObjectName(QString::fromUtf8("Connect"));
        Connect->resize(470, 423);
        recordBrowser = new QTextBrowser(Connect);
        recordBrowser->setObjectName(QString::fromUtf8("recordBrowser"));
        recordBrowser->setGeometry(QRect(10, 0, 451, 261));
        messageText = new QPlainTextEdit(Connect);
        messageText->setObjectName(QString::fromUtf8("messageText"));
        messageText->setGeometry(QRect(10, 300, 451, 85));
        saveRecord = new QCheckBox(Connect);
        saveRecord->setObjectName(QString::fromUtf8("saveRecord"));
        saveRecord->setGeometry(QRect(400, 270, 21, 21));
        sendButton = new QPushButton(Connect);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(370, 390, 89, 24));
        settingButton = new QPushButton(Connect);
        settingButton->setObjectName(QString::fromUtf8("settingButton"));
        settingButton->setGeometry(QRect(290, 270, 21, 21));
        stateLabel = new QLabel(Connect);
        stateLabel->setObjectName(QString::fromUtf8("stateLabel"));
        stateLabel->setGeometry(QRect(10, 400, 72, 15));
        audioButton = new QPushButton(Connect);
        audioButton->setObjectName(QString::fromUtf8("audioButton"));
        audioButton->setGeometry(QRect(90, 270, 21, 21));
        fileButton = new QPushButton(Connect);
        fileButton->setObjectName(QString::fromUtf8("fileButton"));
        fileButton->setGeometry(QRect(10, 270, 21, 21));
        cameraButton = new QPushButton(Connect);
        cameraButton->setObjectName(QString::fromUtf8("cameraButton"));
        cameraButton->setGeometry(QRect(50, 270, 21, 21));
        recordButton = new QPushButton(Connect);
        recordButton->setObjectName(QString::fromUtf8("recordButton"));
        recordButton->setGeometry(QRect(440, 270, 21, 21));

        retranslateUi(Connect);

        QMetaObject::connectSlotsByName(Connect);
    } // setupUi

    void retranslateUi(QWidget *Connect)
    {
        Connect->setWindowTitle(QApplication::translate("Connect", "Form", nullptr));
        saveRecord->setText(QString());
        sendButton->setText(QApplication::translate("Connect", "\345\217\221\351\200\201", nullptr));
#ifndef QT_NO_SHORTCUT
        sendButton->setShortcut(QApplication::translate("Connect", "Ctrl+Return", nullptr));
#endif // QT_NO_SHORTCUT
        settingButton->setText(QString());
        stateLabel->setText(QString());
        audioButton->setText(QString());
        fileButton->setText(QString());
        cameraButton->setText(QString());
        recordButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Connect: public Ui_Connect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECT_H
