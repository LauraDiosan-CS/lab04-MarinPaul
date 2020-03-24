#include "in_out.h"


int main()
{
	tests();
	Service service;
	char op;
	do
	{
		op = meniu_ui();
		switch (op)
		{
		default:	{ no_command(); break; }
		case '1':	{ afisare_ui(service); break; }
		case '2':	{ add_ui(service); break; }
		case '3':	{ del_ui(service); break; }
		case '4':	{ mod_ui(service); break; }
		case '5':	return 0;
		}
	} while (op);
}