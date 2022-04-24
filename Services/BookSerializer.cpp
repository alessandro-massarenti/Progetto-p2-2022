#include "BookSerializer.h"
#include "Models/Book.h"

BookSerializer::BookSerializer(const Book *b) : book(b){}


QJsonObject BookSerializer::getJsonObject() {
    long long a = book->getQuantity();
    QJsonObject record;
    record["title"] = book->getTitle();
    record["author"] = book->getAuthor();
    record["year"] = book->getPubYear();
    record["quantity"] = a;

    return record;
}

