#pragma once

#include "Interfaces/Clearable.h"
#include "Interfaces/Serializable.h"

class Model : public Clearable,public Serializable{

public:
    explicit Model(Serializer* serializer);

    virtual ~Model() = default;
};
