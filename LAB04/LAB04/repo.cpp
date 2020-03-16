#include "repo.h"


Repo::Repo()
{
	this->noMovies = 0;
	this->movies = new Movie[MAX_MOVIES];
}

Repo::~Repo()
{
	if (this->movies)
	{
		delete[] this->movies;
		this->movies = NULL;
		this->noMovies = 0;
	}
}

void Repo::add(const Movie& m)
{
	if (this->noMovies % MAX_MOVIES == 0)
	{
		Movie* moviesAux = new Movie[(noMovies / MAX_MOVIES + 1) * MAX_MOVIES];
		for (int i = 0; i < this->noMovies; i++)
			moviesAux[i] = this->movies[i];
		delete[] this->movies;
		this->movies = moviesAux;
	}
	this->movies[noMovies++] = m;
}

Movie* Repo::getAll()
{
	return movies;
}

int Repo::getNo()
{
	return noMovies;
}