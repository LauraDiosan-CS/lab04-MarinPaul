#include "in_out.h"

void add_ui(Repo& repo)
{	
	char title[100];
	cout << "Introduceti titlul: ";
	cin >> title;
	cout << endl;
	Movie newMovie(title);
	repo.add(newMovie);
	cout << "Adaugat!";
	cout << endl;
}

void afisare_ui(Repo& repo)
{
	cout << "Elementele listei: ";
	for (int i = 0; i < repo.getNo(); i++)
	{
		cout << repo.getAll()[i] << " ";
	}
	cout << endl;
}

char meniu_ui()
{
	char op;
	cout << "Introduceti 1 pentru afisare filme;" << endl
		<< "Introduceti 2 pentru adaugare element;" << endl
		<< "Introduceti 3 pentru iesire." << endl
		<< "Introduceti optiunea: ";
	cin >> op;
	cout << endl;
	return op;
}