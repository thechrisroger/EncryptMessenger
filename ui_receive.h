/********************************************************************************
** Form generated from reading UI file 'receive.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVE_H
#define UI_RECEIVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Receive
{
public:
    QPushButton *pushButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *nameLabel;
    QLineEdit *nameEdit;

    void setupUi(QWidget *Receive)
    {
        if (Receive->objectName().isEmpty())
            Receive->setObjectName(QString::fromUtf8("Receive"));
        Receive->resize(431, 92);
        pushButton = new QPushButton(Receive);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(340, 50, 71, 31));
        widget = new QWidget(Receive);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 401, 31));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(widget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        horizontalLayout->addWidget(nameLabel);

        nameEdit = new QLineEdit(widget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        horizontalLayout->addWidget(nameEdit);


        retranslateUi(Receive);

        QMetaObject::connectSlotsByName(Receive);
    } // setupUi

    void retranslateUi(QWidget *Receive)
    {
        Receive->setWindowTitle(QApplication::translate("Receive", "Form", nullptr));
        pushButton->setText(QApplication::translate("Receive", "\344\277\235\345\255\230", nullptr));
        nameLabel->setText(QApplication::translate("Receive", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Receive: public Ui_Receive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVE_H
