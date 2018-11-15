/********************************************************************************
** Form generated from reading UI file 'friend.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIEND_H
#define UI_FRIEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Friend
{
public:
    QPushButton *sendButton;
    QTextBrowser *recordBrowser;
    QCheckBox *saveRecord;
    QPlainTextEdit *messageText;
    QPushButton *settingButton;
    QLabel *stateLabel;

    void setupUi(QWidget *Friend)
    {
        if (Friend->objectName().isEmpty())
            Friend->setObjectName(QStringLiteral("Friend"));
        Friend->resize(470, 421);
        sendButton = new QPushButton(Friend);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(370, 390, 89, 24));
        sendButton->setAutoDefault(false);
        recordBrowser = new QTextBrowser(Friend);
        recordBrowser->setObjectName(QStringLiteral("recordBrowser"));
        recordBrowser->setGeometry(QRect(10, 0, 451, 261));
        saveRecord = new QCheckBox(Friend);
        saveRecord->setObjectName(QStringLiteral("saveRecord"));
        saveRecord->setGeometry(QRect(402, 270, 21, 21));
        messageText = new QPlainTextEdit(Friend);
        messageText->setObjectName(QStringLiteral("messageText"));
        messageText->setGeometry(QRect(10, 300, 451, 85));
        settingButton = new QPushButton(Friend);
        settingButton->setObjectName(QStringLiteral("settingButton"));
        settingButton->setGeometry(QRect(440, 270, 21, 21));
        settingButton->setAutoDefault(false);
        stateLabel = new QLabel(Friend);
        stateLabel->setObjectName(QStringLiteral("stateLabel"));
        stateLabel->setGeometry(QRect(10, 400, 72, 15));

        retranslateUi(Friend);

        QMetaObject::connectSlotsByName(Friend);
    } // setupUi

    void retranslateUi(QWidget *Friend)
    {
        Friend->setWindowTitle(QApplication::translate("Friend", "Form", nullptr));
        sendButton->setText(QApplication::translate("Friend", "\345\217\221\351\200\201", nullptr));
#ifndef QT_NO_SHORTCUT
        sendButton->setShortcut(QApplication::translate("Friend", "Ctrl+Return", nullptr));
#endif // QT_NO_SHORTCUT
        saveRecord->setText(QString());
        settingButton->setText(QString());
        stateLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Friend: public Ui_Friend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIEND_H
