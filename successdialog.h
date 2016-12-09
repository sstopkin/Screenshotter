#ifndef SUCCESSDIALOG_H
#define SUCCESSDIALOG_H

#include <QDialog>

namespace Ui {
class SuccessDialog;
}

class SuccessDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SuccessDialog(QString, QWidget *parent = 0);
    ~SuccessDialog();

private slots:
    void on_copyToClipbrdButton_clicked();

    void on_closeButton_clicked();

signals:
    void close();

private:
    Ui::SuccessDialog *ui;
    QString url;
};

#endif // SUCCESSDIALOG_H
