/********************************************************************************
** Form generated from reading UI file 'net.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NET_H
#define UI_NET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Net
{
public:

    void setupUi(QWidget *Net)
    {
        if (Net->objectName().isEmpty())
            Net->setObjectName(QStringLiteral("Net"));
        Net->resize(616, 433);

        retranslateUi(Net);

        QMetaObject::connectSlotsByName(Net);
    } // setupUi

    void retranslateUi(QWidget *Net)
    {
        Net->setWindowTitle(QApplication::translate("Net", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Net: public Ui_Net {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NET_H
