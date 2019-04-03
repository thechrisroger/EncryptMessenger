/********************************************************************************
** Form generated from reading UI file 'send.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEND_H
#define UI_SEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Send
{
public:
    QPushButton *selectButton;
    QPushButton *sendButton;
    QPushButton *cancelButton;
    QLabel *stateLabel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *pathLabel;
    QLabel *nameLabel;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *pathEdit;
    QLineEdit *nameEdit;

    void setupUi(QWidget *Send)
    {
        if (Send->objectName().isEmpty())
            Send->setObjectName(QString::fromUtf8("Send"));
        Send->resize(425, 136);
        selectButton = new QPushButton(Send);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));
        selectButton->setGeometry(QRect(170, 90, 71, 28));
        sendButton = new QPushButton(Send);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(342, 90, 81, 28));
        cancelButton = new QPushButton(Send);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(250, 90, 81, 28));
        stateLabel = new QLabel(Send);
        stateLabel->setObjectName(QString::fromUtf8("stateLabel"));
        stateLabel->setGeometry(QRect(10, 110, 101, 21));
        widget = new QWidget(Send);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 20, 401, 53));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pathLabel = new QLabel(widget);
        pathLabel->setObjectName(QString::fromUtf8("pathLabel"));

        verticalLayout->addWidget(pathLabel);

        nameLabel = new QLabel(widget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        verticalLayout->addWidget(nameLabel);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pathEdit = new QLineEdit(widget);
        pathEdit->setObjectName(QString::fromUtf8("pathEdit"));

        verticalLayout_2->addWidget(pathEdit);

        nameEdit = new QLineEdit(widget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        verticalLayout_2->addWidget(nameEdit);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(Send);

        QMetaObject::connectSlotsByName(Send);
    } // setupUi

    void retranslateUi(QWidget *Send)
    {
        Send->setWindowTitle(QApplication::translate("Send", "Form", nullptr));
        selectButton->setText(QApplication::translate("Send", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        sendButton->setText(QApplication::translate("Send", "\345\217\221\351\200\201", nullptr));
        cancelButton->setText(QApplication::translate("Send", "\345\217\226\346\266\210", nullptr));
        stateLabel->setText(QApplication::translate("Send", "\346\234\252\350\277\236\346\216\245", nullptr));
        pathLabel->setText(QApplication::translate("Send", "\350\267\257\345\276\204", nullptr));
        nameLabel->setText(QApplication::translate("Send", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Send: public Ui_Send {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEND_H
