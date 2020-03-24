#include "service.h"


Service::Service() {}

void Service::addMovie(char* title, Date& date, char* genre)
{
	Movie movie(title, date, genre);
	this->repo.add(movie);
}

void Service::delMovie(char* title)
{
	if (this->repo.find_by_title(title) != -1)
	{
		Movie movie = this->repo.getAll()[this->repo.find_by_title(title)];
		this->repo.del(movie);
	}
}

void Service::modMovie(char* title, char* newTitle, Date& newDate, char* newGenre)
{
	if (this->repo.find_by_title(title) != -1)
	{
		Movie old_movie = this->repo.getAll()[this->repo.find_by_title(title)];
		Movie new_movie(newTitle, newDate, newGenre);
		this->repo.mod(old_movie, new_movie);
	}
}

Movie* Service::getAll()
{
	return this->repo.getAll();
}

int Service::getNo()
{
	return this->repo.getNo();
}