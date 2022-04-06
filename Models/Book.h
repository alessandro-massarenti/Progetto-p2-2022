#pragma once

#include <QString>

class Book {
public:
    Book(const QString& name = "",const QString& author = "",int year = 0,unsigned int count = 0);
    virtual ~Book();// = default;

    QString getTitle() const;
    QString getAuthor() const;
    int getPubYear() const;
    unsigned int getQuantity() const;

    void setTitle(const QString& title);
    void setAutor(const QString& author);
    void setPubYear(int idCode);
    void setQuantity(unsigned int quantity);
private:
    QString title;
    QString author;
    int pubYear;
    unsigned int quantity;
};
