#pragma once

#include <string>

class Book {
public:
    Book(const std::string& name = "",const std::string& author = "",const std::string& isbn = "",unsigned int count = 0);
    virtual ~Book() = default;

    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getIdCode() const;
    unsigned int getQuantity() const;

    void setTitle(const std::string& title);
    void setAutor(const std::string& author);
    void setIdCode(const std::string& idCode);
    void setQuantity(unsigned int quantity);
private:
    std::string title;
    std::string author;
    std::string isbn;
    unsigned int quantity;
};
