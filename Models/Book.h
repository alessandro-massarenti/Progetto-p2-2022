#pragma once

#include <QString>

class Book {
public:
    explicit Book(const QString& name = "",const QString& author = "",int year = 0,unsigned int count = 0);
    virtual ~Book() = default;

    [[nodiscard]] QString getTitle() const;
    [[nodiscard]] QString getAuthor() const;
    [[nodiscard]] int getPubYear() const;
    [[nodiscard]] unsigned int getQuantity() const;

    void setTitle(const QString& title);
    void setAuthor(const QString& a);
    void setPubYear(int idCode);
    void setQuantity(unsigned int quantity);
private:
    QString title;
    QString author;
    int pubYear;
    unsigned int quantity;
};
