#ifndef AUXILIARY_H_
#define AUXILIARY_H_

#include <iostream>
#include "author.h"
#include "book_list.h"
#include "book_store.h"

// A string which will be returned to the user if the type of the object is male
extern const std::string MALE_STR;
// A string which will be returned to the userif the type of the object is female
extern const std::string FEMALE_STR;

/*
* The function converts gender into a string
* :param gender
* :return converted string
*/
const std::string convertGenderIntoString(Gender);

/*
* The function compares 2 string
* :param string str1, string str2
* :return true - if they are the same string, otherwise false
*/
bool sameString(const std::string&, const std::string&);

/*
* The function converts BookListResult to StoreResult
* :param store result
* :return converted value
*/
BookStore::StoreResult convertBlrToSr(const BookList::BookListResult&);

#endif //AUXILIARY_H_
