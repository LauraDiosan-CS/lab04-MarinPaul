#pragma once
#include "repo.h"

class Service
{
private:
	Repo repo;
	int noUndo;
	Repo steps[100];
public:
	Service();
	Movie* getAll();
	int getNo();
	void addMovie(char*, Date&, char*);
	void delMovie(char*);
	void modMovie(char*, char*, Date&, char*);
	Repo oneGenre(char*);
	void delBeforeDate(Date&);
	void undo();
};