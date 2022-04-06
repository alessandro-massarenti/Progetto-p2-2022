#include "Book.h"
#include <QDebug>

Book::Book(const QString& n, const QString& a,int i,unsigned int c):
        title(n), author(a), pubYear(i), quantity(c) {
    qDebug() << "Book";
}

QString Book::getTitle() const {
    return title;
}

QString Book::getAuthor() const {
    return author;
}

int Book::getPubYear() const {
    return pubYear;
}

unsigned int Book::getQuantity() const {
    return quantity;
}

void Book::setTitle(const QString &t) {title = t;}

void Book::setAutor(const QString &a) {author = a;}

void Book::setPubYear(int i) { pubYear = i;}

void Book::setQuantity(unsigned int q) {quantity = q;}

Book::~Book() {
    qDebug() << "~Book";
}
