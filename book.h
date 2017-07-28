#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include "author.h"

/*
*
* Book class which encapsulates book real object, which includes information
* about book's author, price, the title and publisher information.
*
*/
class Book {

public:

	/*
	* Book class constructor.
	*
	* title - the title of the book
	* publisher - books publisher name
	* author - books author
	* isbn - books isbn number (book unique identifier)
	* price - books price
	*
	*/
	Book(const std::string title, const std::string publisher, const Author& author, int isbn, double price);

	/*
	* Book copy constructor
	*/
	Book(const Book& _other);

	/*
	* Retrieve book's title
	*/
	std::string getTitle() const;

	/*
	* Retrieve book's publisher name
	*/
	std::string getPublisher() const;

	/*
	* Retrieve book's author
	*/
	Author getAuthor() const;

	/*
	* Retrieve book's price value
	*/
	double getPrice() const;

	/*
	* Retrieve book's isbn identifier
	*/
	int getISBN() const;

	/*
	* Assign book title value
	*/
	Book& setTitle(const std::string title);

	/*
	* Assign publisher name value
	*/
	Book& setPublisher(const std::string publisher);

	/*
	* Assign author to the book
	*/
	Book& setAuthor(const Author& author);

	/*
	* Assign book price value
	*/
	Book& setPrice(double price);

	/*
	* Assign book ISBN identifier value
	*/
	Book& setISBN(int isbn);

	/*
	* Converts book to string representation:
	* "Book title: ____, publisher: ____, ISBN: ____, price: _____, written by: ______."
	*/
	std::string toString() const;

	/*
	* Returns true if and only if book is equal to "other" book parameter,
	* otherwise false
	*/
	bool isEqual(const Book& other) const;

	/*
	* Prints book string representation on the screen
	*/
	const Book& print() const;

	/*
	* determine if 'this' is smaller then 'other' according to the smaller definition between books
	*/
	bool operator<(const Book& other) const;

private:

	/*
	* The book's title
	*/
	std::string _title;

	/*
	* The book's publisher name
	*/
	std::string _publisher;

	/*
	* The book's author
	*/
	Author _author;

	/*
	* The book's isbn identifier
	*/
	int _isbn;

	/*
	* The book's price
	*/
	double _price;

	/*
	* A string which will be printed before the boosk's title in the method toString()
	*/
	static const std::string BOOK_TITLE_STR;

	/*
	* A string which will be printed before the boosk's publisher in the method toString()
	*/
	static const std::string PUBLISHER_STR;

	/*
	* A string which will be printed before the boosk's isbn in the method toString()
	*/
	static const std::string ISBN_STR;

	/*
	* A string which will be printed before the boosk's price in the method toString()
	*/
	static const std::string PRICE_STR;

	/*
	* A string which will be printed before the details of the boosk's author in the method toString()
	*/
	static const std::string AUTHOR_STR;

};


#endif //BOOK_H