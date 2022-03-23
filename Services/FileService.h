#pragma once

#include <QString>

class FileService {
public:
    static bool saveToFile(const QString & data, const QString& path);
    static QString loadFromJson();
};
