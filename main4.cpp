#include <iostream>
#include <string>
#include "author.h"
#include "book.h"
#include "book_store.h"


int main(int argc, const char *argv[]) {

    BookStore store(10);

    Author markTwain("Mark Twain", "twain@google.com", MALE);
    Book book("The Adventures of Tom Sawyer", "Adventures Press", markTwain, 1111, 99.99);

    if ( BookList::SUCCESS == store.addBook(book)) {
        std::cout << "Book added successefuly" << std::endl;
    } else {
        std::cout << "Book already exist in the list" << std::endl;
    }

    Author cormen("Thomas Cormen", "cormen@thomas.org", MALE);
    book.setTitle("Introduction to Algorithms").setPublisher("MIT Press").setAuthor(cormen).setISBN(2222).setPrice(159.00);

    if ( BookList::SUCCESS == store.addBook(book)) {
        std::cout << "Book added successefuly" << std::endl;
    } else {
        std::cout << "Book already exist in the list" << std::endl;
    }

    Author author("Bjarne Stroustrup", "bjarne@google.com", MALE);
    Book cppLang("The C++ Programming Language", "Adison-Wasley", author, 3333, 50.03);

    if ( BookList::SUCCESS == store.addBook(cppLang)) {
        std::cout << "Book added successefuly" << std::endl;
    } else {
        std::cout << "Book already exist in the list" << std::endl;
    }

    author.setName("Scott Mayers").setEmail("mayers@yahoo.com");
    cppLang.setTitle("Effective C++").setISBN(3131).setPrice(47.94).setAuthor(author);

    if ( BookList::SUCCESS == store.addBook(cppLang)) {
        std::cout << "Book added successefuly" << std::endl;
    } else {
        std::cout << "Book already exist in the list" << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    store.print();

    Book newBook("The Adventures of Tom Sawyer", "Adventures Press", markTwain, 1111, 99.99);

    if ( BookList::SUCCESS == store.addBook(newBook)) {
        std::cout << "Book added successefuly" << std::endl;
    } else {
        std::cout << "Book already exist in the list" << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    const Book* lostBook;
    if (NULL != (lostBook = store.findBookByISBN(3131))) {
        std::cout << "Lost book has been found." << std::endl;
        std::cout << "Book title is: " << lostBook->getTitle() << std::endl;
    } else {
        std::cout << "Cannot find book with ISBN: 3131." << std::endl;
    }

    store.removeBook(1111);

    std::cout << std::endl;
    std::cout << std::endl;

    store.print();

    std::cout << std::endl;
    std::cout << std::endl;

    if (NULL!=(lostBook = store.findBookByISBN(1111))) {
        std::cout << "Lost book has been found." << std::endl;
        std::cout << "Book title is:" << lostBook->getTitle() << std::endl;
    } else {
        std::cout << "Cannot find book with ISBN: 1111." << std::endl;
    }


    cppLang.setTitle("More Effective C++").setISBN(3232).setPrice(67.35);

    if ( BookList::SUCCESS == store.addBook(cppLang)) {
        std::cout << "Book added successefuly" << std::endl;
    } else {
        std::cout << "Book already exist in the list" << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    store.print();

    std::cout << std::endl;
    std::cout << std::endl;

    Author clarke("Charles Clarke", "clarke@yahoo.com", MALE);
    Book irBook("Information Retrieval", "MIT Press", clarke, 1717, 62.00);
    store.addBook(irBook);

    BookList scottBooks = store.findAuthorBooks(author);
    std::cout << "Books of " << author.getName() << " in the store." << std::endl;
    scottBooks.print();

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Books of MIT Press." << std::endl;
    BookList mitBooks = store.findPublisherBooks("MIT Press");
    mitBooks.print();

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Books of Adison-Wasley" << std::endl;
    BookList adisonBooks = store.findPublisherBooks("Adison-Wasley");
    adisonBooks.print();

    std::cout << std::endl;
    std::cout << std::endl;

    store.removeBook(3131);
    store.print();

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Books of Adison-Wasley" << std::endl;
    adisonBooks = store.findPublisherBooks("Adison-Wasley");
    adisonBooks.print();
    return 0;
}
