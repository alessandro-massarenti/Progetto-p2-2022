#include "JsonSerializer.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QString>

QJsonObject JsonSerializer::serialize(const Book &b) {
    long long a = b.getQuantity();

    QJsonObject record;
    record["title"] = QString::fromUtf8(b.getTitle());
    record["author"] = QString::fromUtf8(b.getAuthor());
    record["code"] = QString::fromUtf8(b.getIdCode());
    record["quantity"] = a;

    return record;
}

QString JsonSerializer::serialize(const std::vector<Book *> & library) {
    QJsonObject project;

    QJsonArray records;

    for(auto book : library){
        records.append(serialize(*book));
    }
    project["library"] = records;

    QJsonDocument saveDoc(project);
    return saveDoc.toJson();
}
