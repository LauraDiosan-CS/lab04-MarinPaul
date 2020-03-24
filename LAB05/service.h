#pragma once
#include "repo.h"

class Service
{
private:
	Repo repo;
public:
	Service();
	void addMovie(char*, Date&, char*);
	void delMovie(char*);
	void modMovie(char*, char*, Date&, char*);
	Movie* getAll();
	int getNo();
};