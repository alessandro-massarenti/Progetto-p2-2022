#pragma once

#include <string>

class Book {
public:
    Book(std::string name = "",std::string author = "");
    virtual ~Book() = default;

    std::string getName() const;
    std::string getAuthor() const;
    virtual std::string getIdCode() const = 0;
private:
    std::string name;
    std::string author;
};
