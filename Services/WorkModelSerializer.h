#pragma once

#include "Serializer.h"

class WorkModel;

class WorkModelSerializer :public Serializer{
private:
    const WorkModel* model;
public:
    explicit WorkModelSerializer(const WorkModel* workModel);
    QJsonObject getJsonObject() override;


};
