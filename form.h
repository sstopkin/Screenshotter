#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QDebug>

#include <QNetworkAccessManager>
#include <QHttpMultiPart>
#include <QHttpPart>
#include <QNetworkRequest>
#include <QFile>
#include <QIODevice>
#include <QNetworkReply>
#include <QSslSocket>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

private slots:
    void on_saveScreenshot_clicked();
//    void on_cancelButton_clicked();

    void on_pushButton_clicked();

    void imageLoaded(QNetworkReply *);
    void closeAllWindows();

private:
    Ui::Form *ui;
    QPixmap originalPixmap;

    QString capturedDate;
    QString targetFilename;

    QString generateFilename(QString);

    void updateScreenshotLabel();
    void shootScreen();
    void saveScreenshot(QString);
    void uploadScreenshot(QString, QString);
};

#endif // FORM_H
