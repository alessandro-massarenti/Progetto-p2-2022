#pragma once

#include <string>

class Book {
public:
    Book(std::string name = "",std::string author = "");
    virtual ~Book() = default;

    std::string getTitle() const;
    std::string getAuthor() const;
    virtual std::string getIdCode() const = 0;
private:
    std::string title;
    std::string author;
};
