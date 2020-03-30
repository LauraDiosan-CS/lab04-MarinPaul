#include "service.h"


Service::Service()
{
	this->noUndo = 1;
	this->steps[0] = this->repo;
}

Movie* Service::getAll()
{
	return this->repo.getAll();
}

int Service::getNo()
{
	return this->repo.getNo();
}

void Service::addMovie(char* title, Date& date, char* genre)
{
	Movie m(title, date, genre);
	this->repo.add(m);
	this->steps[this->noUndo++] = this->repo;
}

void Service::delMovie(char* title)
{
	if (this->repo.find_by_title(title) != -1)
	{
		Movie m = this->repo.getAll()[this->repo.find_by_title(title)];
		this->repo.del(m);
		this->steps[this->noUndo++] = this->repo;
	}
}

void Service::modMovie(char* title, char* newT, Date& newD, char* newG)
{
	if (this->repo.find_by_title(title) != -1)
	{
		Movie oldM = this->repo.getAll()[this->repo.find_by_title(title)];
		Movie newM(newT, newD, newG);
		this->repo.mod(oldM, newM);
		this->steps[this->noUndo++] = this->repo;
	}
}

Repo Service::oneGenre(char* genre)
{
	Repo sortedMovies;
	for (int i = 0; i < this->repo.getNo(); i++)
		if (strcmp(this->repo.getAll()[i].getGenre(), genre) == 0)
			sortedMovies.add(this->repo.getAll()[i]);
	return sortedMovies;
}

void Service::delBeforeDate(Date& date)
{
	Repo newRepo;
	for (int i = 0; i < this->repo.getNo(); i++)
		if (this->repo.getAll()[i].getDate() > date)
			newRepo.add(this->repo.getAll()[i]);
	if (this->repo != newRepo)
	{
		this->repo = newRepo;
		this->steps[this->noUndo++] = this->repo;
	}
}

void Service::undo()
{
	if (this->noUndo)
	{
		this->noUndo = this->noUndo - 1;
		this->repo = this->steps[this->noUndo - 1];
	}
}