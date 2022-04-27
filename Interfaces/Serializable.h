#pragma once
#include "Services/Serializer.h"
#include <memory>

class Serializable{
protected:
    std::shared_ptr<Serializer> serializer;
    explicit Serializable(Serializer* serializer);
public:
    [[nodiscard]] virtual std::weak_ptr<Serializer> getSerializer() const;
    virtual ~Serializable();
};
