#include "book_store.h"
#include "book_list.h"
#include "book.h"
#include "author.h"
#include "Auxiliary.h"

BookStore::BookStore(int limit) : _booksList(BookList(limit))
{
	this->_totalPrice = 0;
}

BookStore::StoreResult BookStore::addBook(const Book & book)
{
	this->_totalPrice += book.getPrice();
	return convertBlrToSr(this->_booksList.addBook(book));
}

BookStore::StoreResult BookStore::removeBook(int isbn)
{
	const Book* temp = this->_booksList.findBook(isbn);
	if (temp != NULL)
		this->_totalPrice -= temp->getPrice();
	return convertBlrToSr(this->_booksList.removeBook(isbn));
}

const Book * BookStore::findBookByISBN(int isbn) const
{
	return this->_booksList.findBook(isbn);
}

BookList BookStore::findAuthorBooks(const Author & author) const
{
	int numOfAuthBooks = 0;

	for (int i = 0; i < this->_booksList.booksCount(); i++) 
		if (this->_booksList.getBookAtIndex(i)->getAuthor().isEqual(author))
			numOfAuthBooks++;

	if (numOfAuthBooks == 0)
		return NULL;

	BookList authBook(numOfAuthBooks);

	for (int i = 0; i < this->_booksList.booksCount(); i++) 
		if (this->_booksList.getBookAtIndex(i)->getAuthor().isEqual(author))
			authBook.addBook(*(this->_booksList.getBookAtIndex(i)));

	return authBook;
}

BookList BookStore::findPublisherBooks(const std::string & publisher) const
{
	int numOfPubBooks = 0;

	for (int i = 0; i < this->_booksList.booksCount(); i++)
		if (this->_booksList.getBookAtIndex(i)->getPublisher().compare(publisher) == 0)
			numOfPubBooks++;

	if (numOfPubBooks == 0)
		return NULL;

	BookList pubBook(numOfPubBooks);

	for (int i = 0; i < this->_booksList.booksCount(); i++)
		if (this->_booksList.getBookAtIndex(i)->getPublisher().compare(publisher) == 0)
			pubBook.addBook(*(this->_booksList.getBookAtIndex(i)));

	return pubBook;
}

void BookStore::print() const
{
	this->_booksList.print();
}

double BookStore::getTotalPrices() const
{
	return this->_totalPrice;
}

double BookStore::getAvgPrices() const
{
	return this->_totalPrice / this->_booksList.booksCount();
}




