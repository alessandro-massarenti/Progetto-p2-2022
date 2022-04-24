#include "Serializable.h"

Serializable::~Serializable() {
    serializer.reset();
}

std::weak_ptr <Serializer> Serializable::getSerializer() const {
    return serializer;
}

Serializable::Serializable(Serializer *s) : serializer(s){}
