#ifndef AUTHOR_H
#define AUTHOR_H

#include <iostream>

// Type which identifies value for book's author gender
typedef enum { MALE, FEMALE } Gender;

/**
*
* Class which represents book author entity object.
*
**/
class Author {

public:

	/*
	* Author class constructor.
	*/
	Author(const std::string& name, const std::string& email, Gender gender);
	
	/*
	* Retrieve author's name.
	*/
	std::string getName() const;

	/*
	* Retrieve author's email.
	*/
	std::string getEmail() const;

	/*
	* Retrieve author's gender
	*/
	bool getGender() const;

	/*
	* Assign author's name.
	*/
	Author& setName(const std::string& name);

	/*
	* Assign author's email
	*/
	Author& setEmail(std::string email);

	/*
	* Assign author's gender value
	*/
	Author& setGender(Gender gender);

	/*
	* Converts author class representation to string in following format:
	* "Author name: ______, email address: _______, gender:______(male/female)"
	*/
	std::string toString() const;

	/*
	* Prints authors string representation to the standard console output.
	*/
	const Author& print() const;

	/*
	* Returns true whenever author is equal to the "other" parameter,
	* and false otherwise.
	*/
	bool isEqual(const Author& other) const;

private:

	/*
	* The author's name
	*/
	std::string _name;

	/*
	* The author's email
	*/
	std::string _email;

	/*
	* The author's gender
	*/
	Gender _gender;

	/*
	* A string which will be printed before the author's name in the method toString()
	*/
	static const std::string NAME_STR;

	/*
	* A string which will be printed before the author's email in the method toString()
	*/
	static const std::string EMAIL_STR;

	/*
	* A string which will be printed before the author's gender in the method toString()
	*/
	static const std::string GENDER_STR;
};

#endif //AUTHOR_H