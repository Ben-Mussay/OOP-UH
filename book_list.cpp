// Implement of book_list.h 
// Ben Mussay 2017

// Includes
#include <iostream> 
#include <string>
#include "book_list.h"
#include "book.h"

// Constants
const std::string BookList::EMPTY_BOOK_LIST_STR = "Empty Book List.";
const std::string BookList::NOT_EMPTY_BOOK_LIST_STR[] = { "There are ", " book(s)", " in the list"};

BookList::BookList(int limit) : _sizeList(limit)
{
	this->_booksList = new const Book*[this->_sizeList];

	for (int i = 0; i < this->_sizeList; i++)
	{
		this->_booksList[i] = NULL;
	}

	this->_numberOfElements = 0;
}

BookList::BookList(const BookList& other) :
	_sizeList(other._sizeList), _numberOfElements(other._numberOfElements)
{
	this->_booksList = new const Book*[this->_sizeList];

	for (int i = 0; i < this->_sizeList; i++)
	{
		this->_booksList[i] = NULL;
	}

	for (int i = 0; i < other._numberOfElements; i++) 
	{
		this->_booksList[i] = new Book(*(other._booksList[i]));
	}
}

BookList& BookList::operator=(const BookList other) 
{
	if (this == &other)
		return *this;

	for (int i = 0; i < this->_numberOfElements; i++)
		delete this->_booksList[i];
	delete[] this->_booksList;

	this->_sizeList = other._sizeList;
	this->_numberOfElements = other._numberOfElements;
	this->_booksList = new const Book*[this->_sizeList];

	for (int i = 0; i < this->_sizeList; i++)
	{
		this->_booksList[i] = NULL;
	}

	for (int i = 0; i < other._numberOfElements; i++)
	{
		this->_booksList[i] = new Book(*(other._booksList[i]));
	}

	return *this;

}

BookList::BookListResult BookList::addBook(const Book & book)
{
	if (this->_numberOfElements == this->_sizeList)
		return LIST_FULL;

	int index = this->_numberOfElements;

	for(int i = 0; i < this->_numberOfElements; i ++){
		if (this->_booksList[i]->isEqual(book))
			return BOOK_EXISTS;
		if (book < *(this->_booksList[i])) 
		{
			index = i;
			break;
		}
	}

	for (int i = this->_numberOfElements; i >= index; i--)
		this->_booksList[i + 1] = this->_booksList[i];

	this->_booksList[index] = new Book(book);

	this->_numberOfElements++;
	return SUCCESS;
}

BookList::BookListResult BookList::removeBook(const int isbn)
{
	if (this->_numberOfElements == 0)
		return EMPTY_LIST;
	
	for (int i = 0; i < this->_numberOfElements; i++) {
		if (this->_booksList[i]->getISBN() == isbn) {
			for (int j = i; j < this->_numberOfElements; j++) {
				if (j == this->_numberOfElements - 1)
					this->_booksList[j] = NULL;
				else
					this->_booksList[j] = this->_booksList[j + 1];
			}
			this->_numberOfElements--;
			return SUCCESS;
		}
	}

	return BOOK_NOT_FOUND;
}

const Book * BookList::findBook(int isbn) const
{
	for (int i = 0; i < this->_numberOfElements; i++)
		if (this->_booksList[i]->getISBN() == isbn)
			return this->_booksList[i];

	return NULL;
}

int BookList::booksCount() const
{
	return this->_numberOfElements;
}

const Book * BookList::getBookAtIndex(int index) const
{
	if (index >= this->_numberOfElements)
		return NULL;
	
	return this->_booksList[index];
}

void BookList::print() const
{
	if (this->_numberOfElements == 0)
		std::cout << EMPTY_BOOK_LIST_STR << std::endl;
	else{
		std::cout << BookList::NOT_EMPTY_BOOK_LIST_STR[0] << this->_numberOfElements
			<< BookList::NOT_EMPTY_BOOK_LIST_STR[1] << BookList::NOT_EMPTY_BOOK_LIST_STR[2] << std::endl;

		for (int i = 0; i < this->_numberOfElements; i++)
			this->_booksList[i]->print();
	}
}

BookList::~BookList()
{
	for (int i = 0; i < this->_numberOfElements; i++)
		delete this->_booksList[i];

	delete[] this->_booksList;
}

