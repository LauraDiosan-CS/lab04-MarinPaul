#include "in_out.h"


void add_ui(Service& service)
{
	char title[100], genre[100];
	int day, month, year;
	cout << "Introduceti titlul: ";
	cin >> title;
	cout << "Introduceti data lansarii sub forma dd/mm/yyyy: ";
	cin >> day;
	if (cin.get() != '/')
	{
		cout << "Nu ati introdus o data corecta!";
		return;
	}
	cin >> month;
	if (cin.get() != '/')
	{
		cout << "Nu ati introdus o data corecta!";
		return;
	}
	cin >> year;
	cout << "Introduceti genul: ";
	cin >> genre;
	Date date(day, month, year);
	service.addMovie(title, date, genre);
	cout << "Adaugat!" << endl << endl;
}

void del_ui(Service& service)
{
	char title[100];
	cout << "Introduceti titlul: ";
	cin >> title;
	service.delMovie(title);
	cout << "Sters!" << endl << endl;
}

void mod_ui(Service& service)
{
	char title[100];
	cout << "Introduceti titlul filmului pe care doriti sa il modificati: ";
	cin >> title;
	char newTitle[100], newGenre[100];
	int day, month, year;
	cout << "Daca nu doriti sa modificati un detaliu introduceti 0!" << endl << "Introduceti noul titlu: ";
	cin >> newTitle;
	cout << "Introduceti noua data a lansarii sub forma dd/mm/yyyy: ";
	cin >> day;
	if (cin.get() != '/')
	{
		cout << "Nu ati introdus o data corecta!";
		return;
	}
	cin >> month;
	if (cin.get() != '/')
	{
		cout << "Nu ati introdus o data corecta!";
		return;
	}
	cin >> year;
	cout << "Introduceti noul gen: ";
	cin >> newGenre;
	Date newDate(day, month, year);
	service.modMovie(title, newTitle, newDate, newGenre);
	cout << "Modificat!" << endl << endl;
}

void no_command()
{
	cout << "Comanda invalida!" << endl << endl;
}

void afisare_ui(Service& service)
{
	cout << "Elementele listei: " << endl;
	for (int i = 0; i < service.getNo(); i++)
	{
		cout << i + 1 << "." << service.getAll()[i];
	}
	cout << endl;
}

char meniu_ui()
{
	char op;
	cout << "Introduceti 1 pentru afisare filme;" << endl
		<< "Introduceti 2 pentru adaugare element;" << endl
		<< "Introduceti 3 pentru stergere element;" << endl
		<< "Introduceti 4 pentru modificare element;" << endl
		<< "Introduceti 5 pentru iesire." << endl
		<< "Introduceti optiunea: ";
	cin >> op;
	return op;
}