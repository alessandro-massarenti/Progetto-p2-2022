#include "JsonHandler.h"
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

bool JsonHandler::saveToFile(const QString & data, const QString& path) {

    QFile saveFile(path);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't saveToDisk file.");
        return false;
    }
    QTextStream stream(&saveFile);
    stream << data;
    return true;
}

QVector<Book*>* JsonHandler::openFrom(const QString& savePath) {
    QFile loadFile(savePath);

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't loadFromDisk file.");
        return nullptr;
    }

    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    return deSerialize(loadDoc.object());
}

QString JsonHandler::getQstring(std::weak_ptr<Serializer> serializer) {

    if(serializer.expired()) return {};

    QJsonDocument saveDoc(serializer.lock()->getJsonObject());
    return saveDoc.toJson();
}

QVector<Book *> *JsonHandler::deSerialize(const QJsonObject &json) {
    auto aux = new QVector<Book*>;

    auto library = json["library"].toArray();

    for (auto book: library) {

        auto libro = book.toObject();
        
        aux->push_back(new Book(libro["title"].toString(),
                                libro["author"].toString(),
                                libro["year"].toInt(),
                                libro["quantity"].toInt()));
    }
    return aux;
}
