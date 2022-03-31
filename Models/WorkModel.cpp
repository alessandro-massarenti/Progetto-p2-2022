#include "WorkModel.h"

WorkModel::WorkModel(const QString &path) :
        filepath(path) {}

QVector<Book *> &WorkModel::getLibrary() {
    return library;
}

const QString &WorkModel::getSavepath() const {
    return filepath;
}

void WorkModel::setSavePath(const QString &s) {
    filepath = s;
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
