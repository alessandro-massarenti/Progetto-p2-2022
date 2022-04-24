#pragma once

#include <QString>
#include <QJsonObject>
#include "Models/Book.h"
#include <QVector>

/**
 * @brief Classe statica non allocabile
 */
class JsonHandler {
public:
    JsonHandler() = delete;

    static bool saveToFile(const QString & data, const QString& path);
    static QVector<Book*>* openFrom(const QString & savePath);

    static QString serialize(std::weak_ptr<Serializer>);
    static QVector<Book*>* deSerialize(const QJsonObject& jo);
};
