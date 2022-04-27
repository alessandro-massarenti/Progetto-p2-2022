#pragma once

#include "Serializer.h"

class Book;

class BookSerializer : public Serializer{
public:
    explicit BookSerializer(const Book* book);

    QJsonObject getJsonObject() override;
private:
    const Book* book;
};
