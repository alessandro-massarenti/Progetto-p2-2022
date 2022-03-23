#include "FileService.h"
#include <QFile>
#include <QTextStream>

bool FileService::saveToFile(const QString & data, const QString& path) {

    QFile saveFile(path);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't loadFromDisk saveToDisk file.");
        return false;
    }
    QTextStream stream(&saveFile);
    stream << data;
    return true;
}

QString FileService::loadFromJson() {
    return NULL;
}
