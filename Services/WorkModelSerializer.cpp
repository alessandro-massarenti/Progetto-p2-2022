#include "WorkModelSerializer.h"

#include <QJsonArray>
#include "Models/WorkModel.h"

WorkModelSerializer::WorkModelSerializer(const WorkModel *workModel): model(workModel) {}


QJsonObject WorkModelSerializer::getJsonObject() {

    QJsonObject project;
    QJsonArray records;


    for(auto book : model->library){
        records.append(book->getSerializer().lock()->getJsonObject());
    }
    project["library"] = records;

    return project;
}

