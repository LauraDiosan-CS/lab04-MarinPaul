#include "movie.h"


Movie::Movie()
{
	this->title = NULL;
}

Movie::Movie(char* newTitle)
{
	this->title = new char[strlen(newTitle) + 1];
	strcpy_s(this->title, strlen(newTitle) + 1, newTitle);
}

Movie::Movie(const Movie& m)
{
	this->title = new char[strlen(m.title) + 1];
	strcpy_s(this->title, strlen(m.title) + 1, m.title);
}

Movie::~Movie()
{
	if (this->title != NULL)
	{
		delete[] this->title;
		this->title = NULL;
	}
}

char* Movie::getTitle()
{
	return this->title;
}

void Movie::setTitle(char* newTitle)
{
	if (this->title)
		delete[] this->title;
	this->title = new char[strlen(newTitle) + 1];
	strcpy_s(this->title, strlen(newTitle) + 1, newTitle);
}

Movie& Movie::operator=(const Movie& m)
{
	this->setTitle(m.title);
	return *this;
}

bool Movie::operator==(const Movie& m)
{
	return strcmp(this->title, m.title) == 0;
}

ostream& operator<<(ostream& os, const Movie& m)
{
	os << m.title;
	return os;
}