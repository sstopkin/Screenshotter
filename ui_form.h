/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *screenshotLabel;
    QPushButton *saveScreenshot;
    QLineEdit *screenshotFileName;
    QGroupBox *groupBox;
    QListWidget *listWidget;
    QPushButton *cancelButton;
    QPushButton *pushButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(666, 256);
        screenshotLabel = new QLabel(Form);
        screenshotLabel->setObjectName(QStringLiteral("screenshotLabel"));
        screenshotLabel->setGeometry(QRect(10, 10, 381, 231));
        saveScreenshot = new QPushButton(Form);
        saveScreenshot->setObjectName(QStringLiteral("saveScreenshot"));
        saveScreenshot->setGeometry(QRect(410, 220, 80, 22));
        screenshotFileName = new QLineEdit(Form);
        screenshotFileName->setObjectName(QStringLiteral("screenshotFileName"));
        screenshotFileName->setGeometry(QRect(410, 10, 241, 21));
        groupBox = new QGroupBox(Form);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(410, 40, 241, 171));
        listWidget = new QListWidget(groupBox);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(0, 20, 241, 151));
        cancelButton = new QPushButton(Form);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(570, 220, 80, 22));
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(490, 220, 80, 22));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Screenshot", 0));
        screenshotLabel->setText(QString());
        saveScreenshot->setText(QApplication::translate("Form", "Save", 0));
        groupBox->setTitle(QApplication::translate("Form", "Path", 0));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Form", "/home/best", 0));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("Form", "/home/best/\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\270", 0));
        listWidget->setSortingEnabled(__sortingEnabled);

        cancelButton->setText(QApplication::translate("Form", "Cancel", 0));
        pushButton->setText(QApplication::translate("Form", "Send to img", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
