#pragma once
#include "service.h"

class UserInterface
{
private:
	Service service;
public:
	UserInterface();
	void addMovie();
	void delMovie();
	void modMovie();
	void print();
	void oneGenre();
	void delBeforeDate();
	void undo();
	void no_command();
	char meniu();
	int functie();
};