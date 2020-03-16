#ifndef MOVIE_H
#define MOVIE_H
#include <ostream>
using namespace std;
#include <string.h>
class Movie
{
private:
	char* title;
public:
	Movie();
	Movie(char*);
	Movie(const Movie&);
	~Movie();
	char* getTitle();
	void setTitle(char*);
	Movie& operator=(const Movie&);
	bool operator==(const Movie&);
	friend ostream& operator<<(ostream& os, const Movie&);
};
#endif