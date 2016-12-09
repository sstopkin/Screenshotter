/********************************************************************************
** Form generated from reading UI file 'successdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUCCESSDIALOG_H
#define UI_SUCCESSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_SuccessDialog
{
public:
    QTextEdit *textEdit;
    QPushButton *copyToClipbrdButton;
    QPushButton *closeButton;

    void setupUi(QDialog *SuccessDialog)
    {
        if (SuccessDialog->objectName().isEmpty())
            SuccessDialog->setObjectName(QStringLiteral("SuccessDialog"));
        SuccessDialog->resize(267, 207);
        textEdit = new QTextEdit(SuccessDialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 10, 251, 161));
        copyToClipbrdButton = new QPushButton(SuccessDialog);
        copyToClipbrdButton->setObjectName(QStringLiteral("copyToClipbrdButton"));
        copyToClipbrdButton->setGeometry(QRect(10, 181, 121, 21));
        closeButton = new QPushButton(SuccessDialog);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(140, 180, 121, 22));

        retranslateUi(SuccessDialog);

        QMetaObject::connectSlotsByName(SuccessDialog);
    } // setupUi

    void retranslateUi(QDialog *SuccessDialog)
    {
        SuccessDialog->setWindowTitle(QApplication::translate("SuccessDialog", "Dialog", 0));
        copyToClipbrdButton->setText(QApplication::translate("SuccessDialog", "Copy to clipboard", 0));
        closeButton->setText(QApplication::translate("SuccessDialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class SuccessDialog: public Ui_SuccessDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUCCESSDIALOG_H
