#include "in_out.h"


int main()
{
	tests();
	Repo repo;
	char op;
	do
	{
		op = meniu_ui();
		switch (op)
		{
		default:
		{
			cout << "comanda invalida" << endl;
			break;
		}
		case '1':
		{
			afisare_ui(repo);
			break;
		}
		case '2':
		{
			add_ui(repo);
			break;
		}
		case '3':
			return 0;
		}
	} while (op);
}