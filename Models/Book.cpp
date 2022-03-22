#include "Book.h"

Book::Book(const std::string& n, const std::string& a,const std::string& i):
title(n), author(a),isbn(i),quantity(0) {
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getIdCode() const {
    return isbn;
}

unsigned int Book::getQuantity() const {
    return quantity;
}

void Book::setTitle(const std::string &t) {title = t;}

void Book::setAutor(const std::string &a) {author = a;}

void Book::setIdCode(const std::string &i) {isbn = i;}

void Book::setQuantity(unsigned int q) {quantity = q;}
