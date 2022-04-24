#pragma once
#include "Services/Serializer.h"

class Serializable{
protected:
    std::shared_ptr<Serializer> serializer;
    Serializable(Serializer* serializer);
public:
    [[nodiscard]] virtual std::weak_ptr<Serializer> getSerializer() const;
    virtual ~Serializable();
};
