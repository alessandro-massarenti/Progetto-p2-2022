#pragma once

#include "Model.h"
#include <string>
#include <vector>
#include "Book.h"

//Todo: to be defined

class WorkModel : public Model{
public:
    explicit WorkModel(const QString& path = "");
    ~WorkModel() override;


    std::vector<Book*>& getLibrary();
    const QString& getSavepath() const;
    void setSavePath(const QString& savepath);

private:
    QString filepath;
    std::vector<Book*> library;
};
