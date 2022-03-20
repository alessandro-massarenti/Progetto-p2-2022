#pragma once

#include "Model.h"
#include "Book.h"
#include <QString>

//Todo: to be defined

class WorkModel : public Model{
public:
    explicit WorkModel(QString* path);
    WorkModel();

    ~WorkModel() override;

private:
    QString* filepath;
};
