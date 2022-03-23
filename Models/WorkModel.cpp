#include "WorkModel.h"

WorkModel::WorkModel(const QString &path) : filepath(path){
}

WorkModel::~WorkModel() {

}

std::vector<Book *>& WorkModel::getLibrary() {
    return library;
}

const QString &WorkModel::getSavepath() const{
    return filepath;
}

void WorkModel::setSavePath(const QString &s) {
    filepath = s;
}
