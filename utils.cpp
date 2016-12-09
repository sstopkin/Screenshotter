#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "utils.h"

Utils::Utils()
{

}

QStringList Utils::loadPaths(){
    QStringList stringList;
    QFile loadFile("paths.properties");

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open config file.");
        return stringList;
    }

    QTextStream textStream(&loadFile);
    while (true)
    {
        QString line = textStream.readLine();
        if (line.isNull())
            break;
        else
            stringList.append(line);
    }
    qDebug() << "Properties loaded: " << stringList;
    return stringList;
}
