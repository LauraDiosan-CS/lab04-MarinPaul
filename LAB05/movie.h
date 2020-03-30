#pragma once
#include "date.h"
#include <string.h>

class Movie
{
private:
	char* title;
	Date date;
	char* genre;
public:
	Movie();
	Movie(char*, Date&, char*);
	Movie(Movie&);
	~Movie();
	char* getTitle();
	Date& getDate();
	char* getGenre();
	void setTitle(char*);
	void setDate(Date&);
	void setGenre(char*);
	Movie& operator=(Movie&);
	bool operator==(Movie&);
	bool operator!=(Movie&);
	friend ostream& operator<<(ostream&, Movie&);
};