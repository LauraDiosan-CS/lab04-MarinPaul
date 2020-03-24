#include "movie.h"


Movie::Movie()
{
	this->title = NULL;
	this->genre = NULL;
	this->date.day = 0;
	this->date.month = 0;
	this->date.year = 0;
}

Movie::Movie(char* newTitle, const Date& newDate, char* newGenre)
{
	this->title = new char[strlen(newTitle) + 1];
	strcpy_s(this->title, strlen(newTitle) + 1, newTitle);
	this->date = newDate;
	this->genre = new char[strlen(newGenre) + 1];
	strcpy_s(this->genre, strlen(newGenre) + 1, newGenre);
}

Movie::Movie(const Movie& m)
{
	this->title = new char[strlen(m.title) + 1];
	strcpy_s(this->title, strlen(m.title) + 1, m.title);
	this->date = m.date;
	this->genre = new char[strlen(m.genre) + 1];
	strcpy_s(this->genre, strlen(m.genre) + 1, m.genre);
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
	this->date.day = 0;
	this->date.month = 0;
	this->date.year = 0;
}

char* Movie::getTitle()
{
	return this->title;
}

char* Movie::getGenre()
{
	return this->genre;
}

Date& Movie::getDate()
{
	return this->date;
}

void Movie::setTitle(char* newTitle)
{
	if (this->title != NULL)
		delete[] this->title;
	this->title = new char[strlen(newTitle) + 1];
	strcpy_s(this->title, strlen(newTitle) + 1, newTitle);
}

void Movie::setGenre(char* newGenre)
{
	if (this->genre)
		delete[] this->genre;
	this->genre = new char[strlen(newGenre) + 1];
	strcpy_s(this->genre, strlen(newGenre) + 1, newGenre);
}

void Movie::setDate(const Date& newDate)
{
	this->date = newDate;
}

Movie& Movie::operator=(const Movie& m)
{
	this->setTitle(m.title);
	this->setGenre(m.genre);
	this->setDate(m.date);
	return *this;
}

bool Movie::operator==(const Movie& m)
{
	return (strcmp(this->title, m.title) == 0 && strcmp(this->genre, m.genre) == 0 && this->date == m.date);
}

ostream& operator<<(ostream& os, const Movie& m)
{
	os << "Filmul: " << m.title << endl
		<< "  ******" << "Data lansarii: " << m.date.day << "/" << m.date.month << "/" << m.date.year << endl
		<< "  ******" << "Genul:         " << m.genre << endl;
	return os;
}