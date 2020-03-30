#include "userinterface.h"


UserInterface::UserInterface() {}

void UserInterface::addMovie()
{
	char title[100], genre[100];
	int d, m, y;
	cout << "Introduceti titlul: ";
	cin >> title;
	cout << "Introduceti data lansarii sub forma dd/mm/yyyy: ";
	cin >> d;
	if (cin.get() != '/')
	{
		cout << "Nu ati introdus o data corecta!";
		return;
	}
	cin >> m;
	if (cin.get() != '/')
	{
		cout << "Nu ati introdus o data corecta!";
		return;
	}
	cin >> y;
	cout << "Introduceti genul: ";
	cin >> genre;
	Date date(d, m, y);
	this->service.addMovie(title, date, genre);
	cout << "Adaugat!" << endl << endl;
}

void UserInterface::delMovie()
{
	char title[100];
	cout << "Introduceti titlul: ";
	cin >> title;
	this->service.delMovie(title);
	cout << "Sters!" << endl << endl;
}

void UserInterface::modMovie()
{
	char title[100];
	cout << "Introduceti titlul filmului pe care doriti sa il modificati: ";
	cin >> title;
	char newTitle[100], newGenre[100];
	int d, m, y;
	cout << "Daca nu doriti sa modificati un detaliu introduceti 0!" << endl << "Introduceti noul titlu: ";
	cin >> newTitle;
	cout << "Introduceti noua data a lansarii sub forma dd/mm/yyyy: ";
	cin >> d;
	if (cin.get() != '/')
	{
		cout << "Nu ati introdus o data corecta!";
		return;
	}
	cin >> m;
	if (cin.get() != '/')
	{
		cout << "Nu ati introdus o data corecta!";
		return;
	}
	cin >> y;
	cout << "Introduceti noul gen: ";
	cin >> newGenre;
	Date newDate(d, m, y);
	this->service.modMovie(title, newTitle, newDate, newGenre);
	cout << "Modificat!" << endl << endl;
}

void UserInterface::print()
{
	cout << "Elementele listei: " << endl;
	for (int i = 0; i < this->service.getNo(); i++)
	{
		cout << i + 1 << "." << this->service.getAll()[i];
	}
	cout << endl;
}

void UserInterface::oneGenre()
{
	char searchGenre[100];
	cout << "Introduceti genul de cautat: ";
	cin >> searchGenre;
	cout << "Elementele listei: " << endl;
	for (int i = 0; i < service.oneGenre(searchGenre).getNo(); i++)
		cout << service.oneGenre(searchGenre).getAll()[i];
	cout << endl;
}

void UserInterface::delBeforeDate()
{
	int d, m, y;
	cout << "Introduceti data sub forma dd/mm/yyyy: ";
	cin >> d;
	if (cin.get() != '/')
	{
		cout << "Nu ati introdus o data corecta!";
		return;
	}
	cin >> m;
	if (cin.get() != '/')
	{
		cout << "Nu ati introdus o data corecta!";
		return;
	}
	cin >> y;
	Date date(d, m, y);
	this->service.delBeforeDate(date);
	cout << "Sterse!" << endl << endl;
}

void UserInterface::undo()
{
	this->service.undo();
	this->print();
}

void UserInterface::no_command()
{
	cout << "Comanda invalida!" << endl << endl;
}

char UserInterface::meniu()
{
	char op;
	cout << "Introduceti 1 pentru afisare filme;" << endl
		<< "Introduceti 2 pentru adaugare film;" << endl
		<< "Introduceti 3 pentru stergere film;" << endl
		<< "Introduceti 4 pentru modificare film;" << endl
		<< "Introduceti 5 pentru afisarea filmelor de un anumit gen;" << endl
		<< "Introduceti 6 pentru stergere filme mai vechi decat anumita data;" << endl
		<< "Introduceti 7 pentru undo;" << endl
		<< "Introduceti 8 pentru iesire." << endl
		<< "Introduceti optiunea: ";
	cin >> op;
	return op;
}

int UserInterface::functie()
{
	char op;
	do
	{
		op = this->meniu();
		switch (op)
		{
		default: { this->no_command(); break; }
		case '1': { this->print(); break; }
		case '2': { this->addMovie(); break; }
		case '3': { this->delMovie(); break; }
		case '4': { this->modMovie(); break; }
		case '5': { this->oneGenre(); break; }
		case '6': { this->delBeforeDate(); break; }
		case '7': { this->undo(); break; }
		case '8':	return 0;
		}
	} while (op);
}