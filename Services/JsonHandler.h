#pragma once

#include <QString>
#include <QJsonObject>
#include "Models/Book.h"
#include <vector>

/**
 * @brief Classe statica non allocabile
 */
class JsonHandler {
public:
    JsonHandler() = delete;

    static bool saveToFile(const QString & data, const QString& path);
    static std::vector<Book*>* openFrom(const std::string & savePath);

    static QJsonObject serialize(const Book& b);
    static QString serialize(const std::vector<Book*>& library);
    static std::vector<Book*>* deSerialize(const QJsonObject& jo);
};
