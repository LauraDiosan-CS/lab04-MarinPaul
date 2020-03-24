#pragma once
#include "movie.h"

const int MAX_MOVIES = 1;

class Repo
{
private:
	Movie* movies;
	int noMovies;
public:
	Repo();
	~Repo();
	void add(const Movie&);
	void del(const Movie&);
	void mod(Movie&, Movie&);
	int find_by_title(char*);
	int find(const Movie&);
	Movie* getAll();
	int getNo();
	Movie& getMovie(int);
};