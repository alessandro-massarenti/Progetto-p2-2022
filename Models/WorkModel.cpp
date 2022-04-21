#include "WorkModel.h"

WorkModel::WorkModel(){}

QVector<Book *> &WorkModel::getLibrary() {
    return library;
}

QList<QString> WorkModel::getAuthors() {
    QList<QString> authors;
    for (auto book: library) {
        bool trovato = false;
        for (auto author: authors) {
            if (author == book->getAuthor())
                trovato = true;
        }
        if (!trovato) authors.push_back(book->getAuthor());
    }
    return authors;
}

int WorkModel::getSmallestYear() {
    int smallestYear = library[0]->getPubYear();
    for (auto book: library)
        if (book->getPubYear() < smallestYear) smallestYear = book->getPubYear();
    return smallestYear;
}

void WorkModel::clear() {
    while (library.count()) delete library.takeLast();
}
