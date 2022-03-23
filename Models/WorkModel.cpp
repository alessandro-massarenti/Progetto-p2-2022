#include "WorkModel.h"

WorkModel::WorkModel(const std::string &path) : filepath(path){
}

WorkModel::~WorkModel() {

}

std::vector<Book *> WorkModel::getLibrary() {
    return library;
}

const std::string &WorkModel::getSavepath() {
    return filepath;
}
