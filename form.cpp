#include <QApplication>
#include <QWindow>
#include <QScreen>
#include <QDateTime>
#include <QMessageBox>
#include <QDir>

#include "form.h"
#include "ui_form.h"

#include <QRegExp>
#include "successdialog.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    this->ui->listWidget->setCurrentRow(0);
    shootScreen();
    capturedDate = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    targetFilename = generateFilename(capturedDate);
    this->ui->screenshotFileName->setText(targetFilename + ".png");

    connect(this->ui->cancelButton,&QPushButton::clicked,this,&Form::closeAllWindows);
}

Form::~Form()
{
    delete ui;
}

QString Form::generateFilename(QString capturedDate){
    return "Screenshot at " + capturedDate;
}

void Form::shootScreen()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    if (const QWindow *window = windowHandle())
        screen = window->screen();
    if (!screen)
        return;
    originalPixmap = screen->grabWindow(0);
    updateScreenshotLabel();

    //    newScreenshotButton->setDisabled(false);
    //    if (hideThisWindowCheckBox->isChecked())
    //        show();
    QApplication::beep();
}

void Form::saveScreenshot(QString filePath)
{


    if (!originalPixmap.save(filePath+"/"+targetFilename+".png")) {
        QMessageBox::warning(this, tr("Save Error"), tr("The image could not be saved to \"%1\".")
                             .arg(QDir::toNativeSeparators(filePath+"/"+targetFilename)));
    }
}

//void Form::saveToCustomPath(){
    //    const QString format = "png";
    //    QString initialPath = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
    //    if (initialPath.isEmpty())
    //        initialPath = QDir::currentPath();
    //    initialPath += tr("/untitled.") + format;

    //    QFileDialog fileDialog(this, tr("Save As"), initialPath);
    //    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    //    fileDialog.setFileMode(QFileDialog::AnyFile);
    //    fileDialog.setDirectory(initialPath);
    //    QStringList mimeTypes;
    //    foreach (const QByteArray &bf, QImageWriter::supportedMimeTypes())
    //        mimeTypes.append(QLatin1String(bf));
    //    fileDialog.setMimeTypeFilters(mimeTypes);
    //    fileDialog.selectMimeTypeFilter("image/" + format);
    //    fileDialog.setDefaultSuffix(format);
    //    if (fileDialog.exec() != QDialog::Accepted)
    //        return;
    //    const QString fileName = fileDialog.selectedFiles().first();
    //    saveScreenshot(path);
//}

void Form::updateScreenshotLabel()
{
    this->ui->screenshotLabel->setPixmap(originalPixmap.scaled(this->ui->screenshotLabel->size(),
                                                               Qt::KeepAspectRatio,
                                                               Qt::SmoothTransformation));
}

void Form::on_saveScreenshot_clicked()
{
    QString path = this->ui->listWidget->currentItem()->text();
    qDebug() << path << "/" << targetFilename << ".png";
    saveScreenshot(path);
    closeAllWindows();
}

void Form::on_pushButton_clicked()
{
    qDebug() << "/tmp" << targetFilename << ".png";
    saveScreenshot("/tmp");
    uploadScreenshot(targetFilename+".png","/tmp/"+targetFilename+".png");
}

void Form::uploadScreenshot(QString fileName, QString fullPath){

    qDebug() << QSslSocket::sslLibraryVersionString();

    qDebug() << "uploadScreenshot start from" << fileName << fullPath;

    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    QHttpPart imagePart;
    imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/png"));
    imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"userfile\"; filename=\""+ fileName+"\""));

    QFile *file = new QFile(fullPath);
    file->open(QIODevice::ReadOnly);

    imagePart.setBodyDevice(file);

    file->setParent(multiPart); // we cannot delete the file now, so delete it with the multiPart

    multiPart->append(imagePart);

    QUrl url("http://img.omsklug.com/upload");
    QNetworkRequest request(url);

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(imageLoaded(QNetworkReply*)));

    QNetworkReply *reply = manager->post(request, multiPart);
    multiPart->setParent(reply);

    qDebug() << "uploadScreenshot done";

}

void Form::imageLoaded(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    reply->deleteLater();

    QRegExp rx("(http|ftp|https)://([\\w_-]+(?:(?:\\.[\\w_-]+)+))([\\w.,@?^=%&:/~+#-]*[\\w@?^=%&/~+#-])?");
    rx.indexIn(data);
    qDebug() << "imageLoaded responce" << data << rx.cap(0);
    SuccessDialog *dlg=new SuccessDialog(rx.cap(0));
    connect(dlg, SIGNAL(close()),this, SLOT (closeAllWindows()));
    dlg->setModal(true);
    dlg->show();
}

void Form::closeAllWindows()
{
//    connect(this->ui->cancelButton, SIGNAL(clicked()),
//         this, SLOT (closeAllWindows()));
//    connect(exitAction, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));
    QApplication::exit();
}
