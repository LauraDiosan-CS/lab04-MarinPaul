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

void Repo::del(const Movie& m)
{
	this->movies[this->find(m)] = this->movies[noMovies - 1];
	noMovies--;
	if (noMovies % MAX_MOVIES == 0 && noMovies != 0)
	{
		Movie* moviesAux = new Movie[(noMovies / MAX_MOVIES) * MAX_MOVIES];
		for (int i = 0; i < this->noMovies; i++)
			moviesAux[i] = this->movies[i];
		delete[] this->movies;
		this->movies = moviesAux;
	}
}

void Repo::mod(Movie& old_m, Movie& new_m)
{
	int day, month, year;
	int index = this->find(old_m);
	if (strcmp(new_m.getTitle(), "0") == 0)
		new_m.setTitle(this->movies[index].getTitle());
	if (strcmp(new_m.getGenre(), "0") == 0)
		new_m.setGenre(this->movies[index].getGenre());
	if (new_m.getDate().day == 0)
		day = this->movies[index].getDate().day;
	else day = new_m.getDate().day;
	if (new_m.getDate().month == 0)
		month = this->movies[index].getDate().month;
	else month = new_m.getDate().month;
	if (new_m.getDate().year == 0)
		year = this->movies[index].getDate().year;
	else year = new_m.getDate().year;
	Date date(day, month, year);
	new_m.setDate(date);
	this->movies[index] = new_m;
}

int Repo::find_by_title(char* title)
{
	for (int i = 0; i < this->getNo(); i++)
		if (strcmp(this->movies[i].getTitle(), title) == 0)
			return i;
	return -1;
}

int Repo::find(const Movie& m)
{
	for (int i = 0; i < this->getNo(); i++)
		if (this->movies[i] == m)
			return i;
	return -1;
}

Movie* Repo::getAll()
{
	return movies;
}

int Repo::getNo()
{
	return noMovies;
}

Movie& Repo::getMovie(int i)
{
	Movie m;
	if (i < 0 || i >= this->getNo())
		return m;
	return this->movies[i];
}