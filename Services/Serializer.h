#pragma once
#include <QJsonObject>

//Posso avere vari serializer in vari formati, ad esempio in xml
//virtual QXmlObject getXmlObject() = 0;

class Serializer {
public:

    virtual QJsonObject getJsonObject() = 0;

    virtual ~Serializer() = default;
};