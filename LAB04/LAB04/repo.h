#ifndef REPO_H
#define REPO_H
#include "movie.h"

const int MAX_MOVIES = 10;

class Repo
{
private:
	Movie* movies;
	int noMovies;
public:
	Repo();
	~Repo();
	void add(const Movie&);
	Movie* getAll();
	int getNo();
};
#endif