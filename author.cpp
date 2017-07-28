#include <iostream>
#include <string>
#include "author.h"
#include "Auxiliary.h"

const std::string Author::NAME_STR = "Author name: ";
const std::string Author::EMAIL_STR = ", email address: ";
const std::string Author::GENDER_STR = ", gender: ";

Author::Author(const std::string & name, const std::string & email, Gender gender)
{
	this->_name = name;
	this->_email = email;
	this->_gender = gender;
}

std::string Author::getName() const
{
	return this->_name;
}

std::string Author::getEmail() const
{
	return this->_email;
}

bool Author::getGender() const
{
	return this->_gender;
}

Author & Author::setName(const std::string & name)
{
	this->_name = name;
	return *this;
}

Author & Author::setEmail(std::string email)
{
	this->_email = email;
	return *this;
}

Author & Author::setGender(Gender gender)
{
	this->_gender = gender;
	return *this;
}

std::string Author::toString() const
{
	return Author::NAME_STR + this->_name + Author::EMAIL_STR + this->_email +
		Author::GENDER_STR + convertGenderIntoString(this->_gender) + ".";
}

const Author & Author::print() const
{
	std::cout << this->toString() << std::endl;
	return *this;
}

bool Author::isEqual(const Author & other) const
{
	return sameString(this->_name, other._name) && sameString(this->_email, other._email)
		&& (this->_gender == other._gender);
}


