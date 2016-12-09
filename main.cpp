#include <QApplication>
#include <QStyle>
#include <QDesktopWidget>
#include <QCommandLineParser>

#include "form.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("Screenshotter");
    a.setApplicationVersion(VERSION_STRING);

    QCommandLineParser parser;
    parser.setApplicationDescription("Screenshotter app");
    parser.addHelpOption();//Windows only :(
    parser.addVersionOption();

    QCommandLineOption workingMode (QStringList() << "m" << "mode",
                                    QCoreApplication::translate("main", "Working mode."),
                                    "screenshot");
    parser.addOption(workingMode);
    parser.process(a);

    QString mode = parser.value(workingMode);

    Form w;
    w.setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    w.size(),
                    qApp->desktop()->availableGeometry()
                    )
                );
    qDebug() << "mode:" << mode;

    if (mode == "screenshot"){
        QTextStream(stdout) << "Started mode: " << mode << endl;
        w.show();
    }
    else {
        QTextStream(stdout) << "Unsupported mode: " << mode << endl;
        return 1;
    }

    a.exec();
    return 0;
}
