#pragma once

class Model {
public:
    /**@brief pulisce il modello*/
    virtual void clear() = 0;

protected:
    explicit Model() = default;

public:
    virtual ~Model() = default;
};
