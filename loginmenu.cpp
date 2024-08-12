#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "check.h"
#include "register.h"

using namespace std;

string login, passwrd;
extern bool dataTrue;


int main()
{		
	string datauser;
	ifstream ReadData;
	ofstream NewData;
	int choice = 0;
	bool menu = true;

	do {
		cout << "Log in or Register Account:\n";
		cout << "\n1. Log in";
		cout << "\n2. Register Account\n";
		cout << "\n3. Exit program\n";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "\nLoging in\n";
			cout << "Provide login: ";
			cin >> login;
			cout << "\nProvide password: \n";
			cin >> passwrd;
			checkuser(login, passwrd);
			break;
		case 2:		

			createuser();
			break;

		case 3:
			menu = false;
			break;
		default:
			cout << "Choose 1-3 option";
			break;
		}
	} while (menu && !dataTrue);
}