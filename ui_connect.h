/********************************************************************************
** Form generated from reading UI file 'connect.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
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

    void setupUi(QWidget *Connect)
    {
        if (Connect->objectName().isEmpty())
            Connect->setObjectName(QStringLiteral("Connect"));
        Connect->resize(470, 423);
        recordBrowser = new QTextBrowser(Connect);
        recordBrowser->setObjectName(QStringLiteral("recordBrowser"));
        recordBrowser->setGeometry(QRect(10, 0, 451, 261));
        messageText = new QPlainTextEdit(Connect);
        messageText->setObjectName(QStringLiteral("messageText"));
        messageText->setGeometry(QRect(10, 300, 451, 85));
        saveRecord = new QCheckBox(Connect);
        saveRecord->setObjectName(QStringLiteral("saveRecord"));
        saveRecord->setGeometry(QRect(402, 270, 21, 21));
        sendButton = new QPushButton(Connect);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(370, 390, 89, 24));
        settingButton = new QPushButton(Connect);
        settingButton->setObjectName(QStringLiteral("settingButton"));
        settingButton->setGeometry(QRect(440, 270, 21, 21));
        stateLabel = new QLabel(Connect);
        stateLabel->setObjectName(QStringLiteral("stateLabel"));
        stateLabel->setGeometry(QRect(10, 400, 72, 15));

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
    } // retranslateUi

};

namespace Ui {
    class Connect: public Ui_Connect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECT_H
