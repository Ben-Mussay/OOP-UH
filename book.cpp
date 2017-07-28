// Implement of book.h 
// Ben Mussay 2017

// Includes
#include <iostream>
#include <string>
#include "author.h"
#include "book.h"
#include "Auxiliary.h"

// constants 

const std::string Book::BOOK_TITLE_STR = "Book title: ";
const std::string Book::PUBLISHER_STR = ", publisher: ";
const std::string Book::ISBN_STR = ", ISBN: ";
const std::string Book::PRICE_STR = ", price: ";
const std::string Book::AUTHOR_STR = ", written by: ";

Book::Book(const std::string title, const std::string publisher, const Author & author, int isbn,
	double price) : _author(author)
{
	this->_title = title;
	this->_publisher = publisher;
	this->_isbn = isbn;
	this->_price = price;
}

Book::Book(const Book & other) : _author(other._author)
{
	this->_title = other._title;
	this->_publisher = other._publisher;
	this->_isbn = other._isbn;
	this->_price = other._price;
}

std::string Book::getTitle() const
{
	return this->_title;
}

std::string Book::getPublisher() const
{
	return this->_publisher;
}

Author Book::getAuthor() const
{
	return this->_author;
}

double Book::getPrice() const
{
	return this->_price;
}

int Book::getISBN() const
{
	return this->_isbn;
}

Book& Book::setTitle(const std::string title)
{
	this->_title = title;
	return *this;
}

Book& Book::setPublisher(const std::string publisher)
{
	this->_publisher = publisher;
	return *this;
}

Book & Book::setAuthor(const Author & author)
{
	this->_author = author;
	return *this;
}

Book& Book::setPrice(double price)
{
	this->_price = price;
	return *this;
}

Book & Book::setISBN(int isbn)
{
	this->_isbn = isbn;
	return *this;
}

std::string Book::toString() const
{
	return Book::BOOK_TITLE_STR + this->_title + Book::PUBLISHER_STR + this->_publisher + 
		Book::ISBN_STR + std::to_string(this->_isbn) + Book::PRICE_STR + std::to_string(this->_price) +
		Book::AUTHOR_STR + this->_author.getName();
}

bool Book::isEqual(const Book & other) const{
	return sameString(this->_title, other._title) && sameString(this->_publisher, other._publisher) &&
		this->_author.isEqual(other._author) && this->_isbn == other._isbn && 
		this->_price == other._price;
}

const Book & Book::print() const
{
	std::cout << this->toString() << std::endl;
	return *this;
}

/** Duplicate code **/
bool Book::operator<(const Book& other) const
{	
	int cond_int;
	double cond_double;

	// Title
	cond_int = this->_title.compare(other._title);
	if (cond_int > 0)
		return false;
	else if (cond_int < 0)
		return true;

	// Publisher name
	cond_int = this->_publisher.compare(other._publisher);
	if (cond_int > 0)
		return false;
	else if (cond_int < 0)
		return true;

	// Author name
	cond_int = this->_author.getName().compare(other._author.getName());
	if (cond_int > 0)
		return false;
	else if (cond_int < 0)
		return true;

	// Author email
	cond_int = this->_author.getEmail().compare(other._author.getEmail());
	if (cond_int > 0)
		return false;
	else if (cond_int < 0)
		return true;

	// Book's price
	cond_double = this->_price - other._price;
	if (cond_double > 0)
		return false;
	else if (cond_double < 0)
		return true;

	// ISBN
	cond_int = this->_isbn - other._isbn;
	if (cond_int > 0)
		return false;
	
	return true;

}
