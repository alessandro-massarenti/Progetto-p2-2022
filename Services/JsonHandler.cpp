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

std::vector<Book*>* JsonHandler::openFrom(const QString& savePath) {
    QFile loadFile(savePath);

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't loadFromDisk file.");
        return nullptr;
    }

    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    return deSerialize(loadDoc.object());
}

QJsonObject JsonHandler::serialize(const Book &b) {
    long long a = b.getQuantity();

    QJsonObject record;
    record["title"] = b.getTitle();
    record["author"] = b.getAuthor();
    record["code"] = b.getIdCode();
    record["quantity"] = a;

    return record;
}

QString JsonHandler::serialize(const std::vector<Book *> & library) {
    QJsonObject project;

    QJsonArray records;


    for(auto book : library){
        records.append(serialize(*book));
    }
    project["library"] = records;

    QJsonDocument saveDoc(project);
    return saveDoc.toJson();
}

std::vector<Book *> *JsonHandler::deSerialize(const QJsonObject &json) {
    auto aux = new std::vector<Book*>;

    auto library = json["library"].toArray();

    for (auto book: library) {

        auto libro = book.toObject();
        aux->push_back(new Book(libro["title"].toString(),
                                libro["author"].toString(),
                                libro["code"].toString(),
                                libro["quantity"].toInt()));
    }
    return aux;
}
