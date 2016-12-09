#include "successdialog.h"
#include "ui_successdialog.h"
#include <QClipboard>

SuccessDialog::SuccessDialog(QString m_url, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SuccessDialog),
    url(m_url)
{
    ui->setupUi(this);
    ui->textEdit->setText(url);
}

SuccessDialog::~SuccessDialog()
{
    delete ui;
}

void SuccessDialog::on_copyToClipbrdButton_clicked()
{
    QClipboard *p_Clipboard = QApplication::clipboard();
    p_Clipboard->setText(url);
    emit close();
}

void SuccessDialog::on_closeButton_clicked()
{
    emit close();
}
