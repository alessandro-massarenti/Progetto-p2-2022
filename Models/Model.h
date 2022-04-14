#pragma once

#include "Interfaces/Clearable.h"

class Model : public Clearable{

protected:
    explicit Model() = default;

public:
    virtual ~Model() = default;
};
