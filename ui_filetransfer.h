/********************************************************************************
** Form generated from reading UI file 'filetransfer.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILETRANSFER_H
#define UI_FILETRANSFER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileTransfer
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *pathLine;
    QLineEdit *nameLine;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *pathLabel;
    QLabel *nameLabel;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *selectButton;
    QPushButton *cancelButton;
    QPushButton *sendButton;
    QLabel *fileState;

    void setupUi(QWidget *FileTransfer)
    {
        if (FileTransfer->objectName().isEmpty())
            FileTransfer->setObjectName(QStringLiteral("FileTransfer"));
        FileTransfer->resize(420, 115);
        layoutWidget = new QWidget(FileTransfer);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 10, 351, 61));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pathLine = new QLineEdit(layoutWidget);
        pathLine->setObjectName(QStringLiteral("pathLine"));
        pathLine->setEnabled(true);

        verticalLayout_2->addWidget(pathLine);

        nameLine = new QLineEdit(layoutWidget);
        nameLine->setObjectName(QStringLiteral("nameLine"));
        nameLine->setEnabled(true);

        verticalLayout_2->addWidget(nameLine);

        layoutWidget1 = new QWidget(FileTransfer);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 41, 61));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pathLabel = new QLabel(layoutWidget1);
        pathLabel->setObjectName(QStringLiteral("pathLabel"));

        verticalLayout->addWidget(pathLabel);

        nameLabel = new QLabel(layoutWidget1);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        verticalLayout->addWidget(nameLabel);

        layoutWidget2 = new QWidget(FileTransfer);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(150, 80, 256, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        selectButton = new QPushButton(layoutWidget2);
        selectButton->setObjectName(QStringLiteral("selectButton"));

        horizontalLayout->addWidget(selectButton);

        cancelButton = new QPushButton(layoutWidget2);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        sendButton = new QPushButton(layoutWidget2);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        horizontalLayout->addWidget(sendButton);

        fileState = new QLabel(FileTransfer);
        fileState->setObjectName(QStringLiteral("fileState"));
        fileState->setGeometry(QRect(10, 80, 91, 16));

        retranslateUi(FileTransfer);

        QMetaObject::connectSlotsByName(FileTransfer);
    } // setupUi

    void retranslateUi(QWidget *FileTransfer)
    {
        FileTransfer->setWindowTitle(QApplication::translate("FileTransfer", "Form", nullptr));
        pathLabel->setText(QApplication::translate("FileTransfer", "\350\267\257\345\276\204", nullptr));
        nameLabel->setText(QApplication::translate("FileTransfer", "\346\226\207\344\273\266", nullptr));
        selectButton->setText(QApplication::translate("FileTransfer", "\346\265\217\350\247\210\346\226\207\344\273\266", nullptr));
        cancelButton->setText(QApplication::translate("FileTransfer", "\345\217\226\346\266\210", nullptr));
        sendButton->setText(QApplication::translate("FileTransfer", "\345\217\221\351\200\201", nullptr));
        fileState->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FileTransfer: public Ui_FileTransfer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILETRANSFER_H
