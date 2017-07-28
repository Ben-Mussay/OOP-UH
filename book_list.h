#ifndef BOOK_LIST_H
#define BOOK_LIST_H

#include <iostream>
#include "book.h"

/*
*
* Class which represents list of the books with constant size, which keeps
* list of books and enables action such as:
*
*  - add new book to the list
*  - remove existing book from the the list
*  - find book which existed in the list
*  - books count
*
*/
class BookList {

public:

	/*
	* Result types for class methods add/remove book.
	*
	* LIST_FULL - represents whenever list is full
	* EMPTY_LIST - represents empty list
	* BOOK_EXISTS - book has been already stored in the list
	* BOOK_NOT_FOUND - no book found in the list
	* SUCCESS - operation completed succeseful
	*
	*/
	typedef enum { LIST_FULL, EMPTY_LIST, BOOK_EXISTS, BOOK_NOT_FOUND, SUCCESS } BookListResult;

	/*
	* BookList constructor which creates books list of given size.
	*
	*  limit - maximum list size
	*/
	BookList(int limit);

	/*
	* Copy constructor which capabale to initialize new books list instance, given already existing list.
	*/
	BookList(const BookList& other);

	/*
	* Assignment operator which capabale to copy internal information from already existing list.
	*/
	BookList& operator=(const BookList other);

	/*
	* Adds new books to the list
	*
	* RETURNS:
	*
	*  - LIST_FULL - in case book list size reached the limit
	*  - BOOK_EXISTS - same book is already existed in the list
	*  - SUCCESS - book was succesefully added to the list
	*/
	BookList::BookListResult addBook(const Book& book);

	/*
	* Removes books from the list
	*
	* RETURNS:
	*
	*  - EMPTY_LIST - books list is empty
	*  - BOOK_NOT_FOUND - no book found in the list
	*  - SUCCESS - book was succesefully removed from the list
	*/
	BookListResult removeBook(const int isbn);

	/*
	* Find a book with given "isbn" indentifier.
	*
	* RETURNS:
	*
	*  - constant pointer to the book from the list in case it was found
	*  - NULL ponter in case no book exists with given "isbn"
	*/
	const Book* findBook(int isbn) const;

	/*
	* Returns number of books in the list
	*/
	int booksCount() const;

	/*
	* Returns const pointer to the book at given index, should return NULL
	* pointer in case there are less books than given index value
	*/
	const Book* getBookAtIndex(int index) const;

	/*
	* Prints list of books.
	*
	* If there are no books in the list method should print:
	* "Empty Book List."
	*
	* Otherwise method should output:
	*
	* "There are ___ book(s) in the list"
	* Then output books and prints out book string representation.
	* Printed list should be in descending order according to the:
	*
	* 1. Title value
	* 2. Publisher name value
	* 3. Author name
	* 4. Author email
	* 5. Book's price
	* 6. ISBN
	*/
	void print() const;

	/*
	* Destructor which capable to release all allocated resources if
	* needed.
	*/
	~BookList();

private:
	/*
	* List of books
	*/
	const Book** _booksList;

	/*
	* The size of the book's list
	*/
	int _sizeList;

	/*
	* Number of books in the list
	*/
	int _numberOfElements;

	/*
	* A string which will be printed if there are no books in the list
	*/
	static const std::string EMPTY_BOOK_LIST_STR;

	/*
	* A strings which will be printed if there are books in the list
	*/
	static const std::string NOT_EMPTY_BOOK_LIST_STR[3];

};


#endif //BOOK_LIST_H