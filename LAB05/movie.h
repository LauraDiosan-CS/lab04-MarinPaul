#pragma once
#include <iostream>
#include "date.h"
#include <string.h>

using namespace std;

class Movie
{
private:
	char* title;
	Date date;
	char* genre;
public:
	Movie();
	Movie(char*, const Date&, char*);
	Movie(const Movie&);
	~Movie();
	char* getTitle();
	char* getGenre();
	Date& getDate();
	void setTitle(char*);
	void setGenre(char*);
	void setDate(const Date&);
	Movie& operator=(const Movie&);
	bool operator==(const Movie&);
	friend ostream& operator<<(ostream& os, const Movie&);
};