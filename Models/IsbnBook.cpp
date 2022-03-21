#include "IsbnBook.h"

IsbnBook::IsbnBook(const std::string & t,const std::string & a,const std::string & i) :
Book(t,a),isbn(i){}

std::string IsbnBook::getIdCode() const {
    return isbn;
}


