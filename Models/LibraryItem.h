#pragma once

#include "Book.h"

class LibraryItem {

public:
    LibraryItem();
    unsigned int getCount();
    Book* getBook();

private:
    unsigned int count;
};

