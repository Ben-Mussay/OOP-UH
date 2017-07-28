// Implement of Auxiliary.h
// Ben Mussay 2017

// Includes
#include <iostream>
#include <string>
#include "author.h"
#include "Auxiliary.h"
#include "book_list.h"
#include "book_store.h"

// Constants
const std::string MALE_STR = "male";
const std::string FEMALE_STR = "female";

const std::string convertGenderIntoString(Gender gender) 
{
	if (gender == MALE)
		return MALE_STR;
	return FEMALE_STR;
}

bool sameString(const std::string& str1, const std::string& str2) 
{
	return !str1.compare(str2);
}


BookStore::StoreResult convertBlrToSr(const BookList::BookListResult& result) 
{
	switch (result) 
	{
		case BookList::LIST_FULL : 
			return BookStore::FULL_STORE;
		case BookList::EMPTY_LIST :
			return BookStore::EMPTY_STORE;
		case BookList::BOOK_EXISTS :
			return BookStore::BOOK_EXISTS;
		case BookList::BOOK_NOT_FOUND :
			return BookStore::BOOK_NOT_FOUND;
		default: // Success
			return BookStore::SUCCESS;
	}
}
