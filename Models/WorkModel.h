#pragma once

#include "Model.h"
#include <string>
#include <vector>

//Todo: to be defined

class WorkModel : public Model{
public:
    explicit WorkModel(const std::string& path);
    WorkModel();
    ~WorkModel() override;

private:
    std::string filepath;
};
