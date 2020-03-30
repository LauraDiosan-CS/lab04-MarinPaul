#include "movie.h"


Movie::Movie()
{
	this->title = NULL;
	this->genre = NULL;
	this->date;
}

Movie::Movie(char* newTitle, Date& newDate, char* newGenre)
{
	this->title = new char[strlen(newTitle) + 1];
	strcpy_s(this->title, strlen(newTitle) + 1, newTitle);
	this->date = newDate;
	this->genre = new char[strlen(newGenre) + 1];
	strcpy_s(this->genre, strlen(newGenre) + 1, newGenre);
}

Movie::Movie(Movie& m)
{
	*this = m;
}

Movie::~Movie()
{
	if (this->title)
	{
		delete[] this->title;
		this->title = NULL;
	}
	if (this->genre)
	{
		delete[] this->genre;
		this->genre = NULL;
	}
}

char* Movie::getTitle()
{
	return this->title;
}

Date& Movie::getDate()
{
	return this->date;
}

char* Movie::getGenre()
{
	return this->genre;
}

void Movie::setTitle(char* newTitle)
{
	if (this->title != NULL)
		delete[] this->title;
	this->title = new char[strlen(newTitle) + 1];
	strcpy_s(this->title, strlen(newTitle) + 1, newTitle);
}

void Movie::setDate(Date& newDate)
{
	this->date = newDate;
}

void Movie::setGenre(char* newGenre)
{
	if (this->genre)
		delete[] this->genre;
	this->genre = new char[strlen(newGenre) + 1];
	strcpy_s(this->genre, strlen(newGenre) + 1, newGenre);
}

Movie& Movie::operator=(Movie& m)
{
	this->setTitle(m.title);
	this->setGenre(m.genre);
	this->setDate(m.date);
	return *this;
}

bool Movie::operator==(Movie& m)
{
	return (strcmp(this->title, m.title) == 0 && strcmp(this->genre, m.genre) == 0 && this->date == m.date);
}

bool Movie::operator!=(Movie& m)
{
	return !this->operator==(m);
}

ostream& operator<<(ostream& os, Movie& m)
{
	os << "Filmul: " << m.title << endl
		<< "  ******" << "Data lansarii: " << m.date << endl
		<< "  ******" << "Genul:         " << m.genre << endl;
	return os;
}