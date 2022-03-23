#pragma once

#include <QString>

class Book {
public:
    Book(const QString& name = "",const QString& author = "",const QString& isbn = "",unsigned int count = 0);
    virtual ~Book() = default;

    QString getTitle() const;
    QString getAuthor() const;
    QString getIdCode() const;
    unsigned int getQuantity() const;

    void setTitle(const QString& title);
    void setAutor(const QString& author);
    void setIdCode(const QString& idCode);
    void setQuantity(unsigned int quantity);
private:
    QString title;
    QString author;
    QString isbn;
    unsigned int quantity;
};
