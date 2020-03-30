#pragma once
#include "movie.h"

class Repo
{
private:
	Movie movies[30];
	int noMovies;
public:
	Repo();
	Repo(Repo&);
	~Repo();
	Repo& operator=(Repo&);
	bool operator==(Repo&);
	bool operator!=(Repo&);
	void add(Movie&);
	void del(Movie&);
	void mod(Movie&, Movie&);
	Movie* getAll();
	int getNo();
	int find_by_title(char*);
	int find(Movie&);
};