#pragma once
#include <QJsonObject>

class Serializer {
public:

    virtual QJsonObject getJsonObject() = 0;
    virtual ~Serializer() = default;
};