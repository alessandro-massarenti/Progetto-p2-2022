#pragma once

#include "Model.h"
#include <string>
#include <vector>
#include "Book.h"

//Todo: to be defined

class WorkModel : public Model{
public:
    explicit WorkModel(const std::string& path = "/Users/alessandro/Desktop/Prova.json");
    ~WorkModel() override;


    std::vector<Book*> getLibrary();
    const std::string& getSavepath();

private:
    std::string filepath;
    std::vector<Book*> library;
};
