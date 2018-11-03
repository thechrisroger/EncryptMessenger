/********************************************************************************
** Form generated from reading UI file 'file.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILE_H
#define UI_FILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_File
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *fileLineEdit;
    QLabel *fileLabel;
    QLineEdit *pathLineEdit;
    QLabel *pathLabel;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *selectButton;
    QPushButton *cancelButton;
    QPushButton *sendButton;

    void setupUi(QWidget *File)
    {
        if (File->objectName().isEmpty())
            File->setObjectName(QStringLiteral("File"));
        File->resize(444, 191);
        layoutWidget = new QWidget(File);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 421, 81));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        fileLineEdit = new QLineEdit(layoutWidget);
        fileLineEdit->setObjectName(QStringLiteral("fileLineEdit"));

        gridLayout->addWidget(fileLineEdit, 1, 1, 1, 1);

        fileLabel = new QLabel(layoutWidget);
        fileLabel->setObjectName(QStringLiteral("fileLabel"));

        gridLayout->addWidget(fileLabel, 1, 0, 1, 1);

        pathLineEdit = new QLineEdit(layoutWidget);
        pathLineEdit->setObjectName(QStringLiteral("pathLineEdit"));

        gridLayout->addWidget(pathLineEdit, 0, 1, 1, 1);

        pathLabel = new QLabel(layoutWidget);
        pathLabel->setObjectName(QStringLiteral("pathLabel"));

        gridLayout->addWidget(pathLabel, 0, 0, 1, 1);

        layoutWidget1 = new QWidget(File);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(120, 140, 311, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        selectButton = new QPushButton(layoutWidget1);
        selectButton->setObjectName(QStringLiteral("selectButton"));

        horizontalLayout->addWidget(selectButton);

        cancelButton = new QPushButton(layoutWidget1);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        sendButton = new QPushButton(layoutWidget1);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        horizontalLayout->addWidget(sendButton);


        retranslateUi(File);

        QMetaObject::connectSlotsByName(File);
    } // setupUi

    void retranslateUi(QWidget *File)
    {
        File->setWindowTitle(QApplication::translate("File", "Form", nullptr));
        fileLabel->setText(QApplication::translate("File", "\346\226\207\344\273\266", nullptr));
        pathLabel->setText(QApplication::translate("File", "\350\267\257\345\276\204", nullptr));
        selectButton->setText(QApplication::translate("File", "\351\200\211\346\213\251", nullptr));
        cancelButton->setText(QApplication::translate("File", "\345\217\226\346\266\210", nullptr));
        sendButton->setText(QApplication::translate("File", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class File: public Ui_File {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILE_H
