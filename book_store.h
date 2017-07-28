#ifndef BOOK_STORE_H
#define BOOK_STORE_H

#include <iostream>
#include "author.h"
#include "book.h"
#include "book_list.h"

/*
*
* Class which represents book store object, with following capabilities:
*
*  - store new book
*  - remove existing book
*  - calculate different statistics
*  - find books of given author
*  - find books which were published with same publisher
*
*/
class BookStore
{
public:

	/*
	* Result type for methods add/remove book to the store
	*/
	typedef enum
	{
		EMPTY_STORE,
		FULL_STORE,
		BOOK_NOT_FOUND,
		BOOK_EXISTS,
		SUCCESS
	} StoreResult;

	/*
	* Book store constructor, which creates book store of limited book
	* list.
	*/
	BookStore(int limit);

	/*
	* Add new book to the store.
	*
	* RETURNS:
	*  - SUCCESS - operation completed successfully
	*  - FULL_STORE - no place in store to add new book
	*  - BOOK_EXISTS - book equal to newly added already exists in the store
	*/
	StoreResult addBook(const Book& book);

	/*
	* Removes new book from the store.
	*
	* RETURNS:
	*  - SUCCESS - operation completed successfully
	*  - EMPTY_STORE - there is no book in the store to delete
	*  - BOOK_NOT_FOUND - there is no book to delete in the store
	*/
	StoreResult removeBook(int isbn);

	/*
	* Finds book in the store by its ISBN number and returns
	* Returns constant pointer to found book, NULL pointer in case pointer wasn't found.
	*/
	const Book* findBookByISBN(int isbn) const;

	/*
	* Given author information returns book list with books authored by
	* him, in case there are no books of given author return an empty list.
	*/
	BookList findAuthorBooks(const Author& author) const;

	/*
	* Given publisher name returns list of book published by him, if there
	* are no books in the store of publisher return empty list.
	*/
	BookList findPublisherBooks(const std::string& publisher) const;

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
	* 4. Authors email
	* 5. Book's price
	* 6. ISBN
	*/
	void print() const;

	/*
	* Method computes all sum prices of books in the store and returns it.
	*/
	double getTotalPrices() const;

	/*
	* Method computes average price of books in the store and returns it.
	*/
	double getAvgPrices() const;

private:

	/*
	* List of all the books in the store
	*/
	BookList _booksList;

	/*
	* The total price of the books in the store
	*/
	double _totalPrice;

};

#endif //BOOK_STORE_H
