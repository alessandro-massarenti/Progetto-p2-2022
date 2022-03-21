#include "Book.h"

Book::Book(std::string n, std::string a): title(n), author(a) {
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}
