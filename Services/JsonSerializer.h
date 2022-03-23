#pragma once

#include <QJsonObject>
#include "Models/Book.h"
#include <vector>

class JsonSerializer {
public:
    static QJsonObject serialize(const Book& b);
    static QString serialize(const std::vector<Book*>& library);
};
