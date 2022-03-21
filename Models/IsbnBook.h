#pragma once

#include "Book.h"

class IsbnBook : public Book{
public:
    IsbnBook(const std::string & title = "",const std::string & author = "",const std::string & isbn = "");
    std::string getIdCode() const override;

private:
    std::string isbn;
};

