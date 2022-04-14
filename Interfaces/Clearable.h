#pragma once

class Clearable {
public:
    virtual ~Clearable() = default;
    virtual void clear() = 0;
};
