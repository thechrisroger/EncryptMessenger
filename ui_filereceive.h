/********************************************************************************
** Form generated from reading UI file 'filereceive.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILERECEIVE_H
#define UI_FILERECEIVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileReceive
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *pathLabel;
    QLabel *nameLabel;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *pathLine;
    QLineEdit *nameLine;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *yesButton;
    QPushButton *viewButton;

    void setupUi(QWidget *FileReceive)
    {
        if (FileReceive->objectName().isEmpty())
            FileReceive->setObjectName(QStringLiteral("FileReceive"));
        FileReceive->resize(420, 115);
        widget = new QWidget(FileReceive);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 62, 61));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pathLabel = new QLabel(widget);
        pathLabel->setObjectName(QStringLiteral("pathLabel"));

        verticalLayout->addWidget(pathLabel);

        nameLabel = new QLabel(widget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        verticalLayout->addWidget(nameLabel);

        widget1 = new QWidget(FileReceive);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(80, 10, 331, 61));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pathLine = new QLineEdit(widget1);
        pathLine->setObjectName(QStringLiteral("pathLine"));

        verticalLayout_2->addWidget(pathLine);

        nameLine = new QLineEdit(widget1);
        nameLine->setObjectName(QStringLiteral("nameLine"));

        verticalLayout_2->addWidget(nameLine);

        widget2 = new QWidget(FileReceive);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(220, 80, 187, 26));
        horizontalLayout = new QHBoxLayout(widget2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        yesButton = new QPushButton(widget2);
        yesButton->setObjectName(QStringLiteral("yesButton"));

        horizontalLayout->addWidget(yesButton);

        viewButton = new QPushButton(widget2);
        viewButton->setObjectName(QStringLiteral("viewButton"));

        horizontalLayout->addWidget(viewButton);


        retranslateUi(FileReceive);

        QMetaObject::connectSlotsByName(FileReceive);
    } // setupUi

    void retranslateUi(QWidget *FileReceive)
    {
        FileReceive->setWindowTitle(QApplication::translate("FileReceive", "Form", nullptr));
        pathLabel->setText(QApplication::translate("FileReceive", "\344\277\235\345\255\230\350\267\257\345\276\204", nullptr));
        nameLabel->setText(QApplication::translate("FileReceive", "\346\226\207\344\273\266\345\220\215\347\247\260", nullptr));
        yesButton->setText(QApplication::translate("FileReceive", "\347\241\256\345\256\232", nullptr));
        viewButton->setText(QApplication::translate("FileReceive", "\346\237\245\347\234\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileReceive: public Ui_FileReceive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILERECEIVE_H
