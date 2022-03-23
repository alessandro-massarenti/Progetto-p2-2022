#include "Book.h"

Book::Book(const QString& n, const QString& a,const QString& i,unsigned int c):
title(n), author(a),isbn(i),quantity(c) {
}

QString Book::getTitle() const {
    return title;
}

QString Book::getAuthor() const {
    return author;
}

QString Book::getIdCode() const {
    return isbn;
}

unsigned int Book::getQuantity() const {
    return quantity;
}

void Book::setTitle(const QString &t) {title = t;}

void Book::setAutor(const QString &a) {author = a;}

void Book::setIdCode(const QString &i) {isbn = i;}

void Book::setQuantity(unsigned int q) {quantity = q;}
