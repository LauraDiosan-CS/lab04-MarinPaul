#include "repo.h"


Repo::Repo()
{
	this->noMovies = 0;
}

Repo::Repo(Repo& r)
{
	*this = r;
}

Repo::~Repo()
{
	this->noMovies = 0;
}

Repo& Repo::operator=(Repo& r)
{
	this->noMovies = r.noMovies;
	for (int i = 0; i < this->noMovies; i++)
		this->movies[i] = r.movies[i];
	return *this;
}

bool Repo::operator==(Repo& r)
{
	if (this->noMovies != r.noMovies)
		return false;
	for (int i = 0; i < this->noMovies; i++)
		if (r.find(this->movies[i]) == -1)
			return false;
	return true;
}

bool Repo::operator!=(Repo& r)
{
	return !this->operator==(r);
}

void Repo::add(Movie& m)
{
	this->movies[this->noMovies++] = m;
}

void Repo::del(Movie& m)
{
	this->movies[this->find(m)] = this->movies[noMovies - 1];
	this->noMovies = this->noMovies - 1;
}

void Repo::mod(Movie& oldM, Movie& newM)
{
	if (strcmp(newM.getTitle(), "0") == 0)
		newM.setTitle(oldM.getTitle());
	int d, m, y;
	if (newM.getDate().d == 0)
		d = oldM.getDate().d;
	else d = newM.getDate().d;
	if (newM.getDate().m == 0)
		m = oldM.getDate().m;
	else m = newM.getDate().m;
	if (newM.getDate().y == 0)
		y = oldM.getDate().y;
	else y = newM.getDate().y;
	Date date(d, m, y);
	newM.setDate(date);
	if (strcmp(newM.getGenre(), "0") == 0)
		newM.setGenre(oldM.getGenre());
	this->movies[this->find(oldM)] = newM;
}

Movie* Repo::getAll()
{
	return movies;
}

int Repo::getNo()
{
	return noMovies;
}

int Repo::find_by_title(char* title)
{
	for (int i = 0; i < noMovies; i++)
		if (strcmp(this->movies[i].getTitle(), title) == 0)
			return i;
	return -1;
}

int Repo::find(Movie& m)
{
	for (int i = 0; i < noMovies; i++)
		if (this->movies[i] == m)
			return i;
	return -1;
}