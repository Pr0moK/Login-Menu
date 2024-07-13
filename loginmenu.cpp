#include <iostream>
#include <fstream>
#include <string>
#include "check.h"

using namespace std;

string login, passwrd;
extern int dataTrue;


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
			cout << "\nRegistry \n";

			cout << "\nProvide login:"; cin >> login; cout << "\n";
			cout << "\nProvide password: "; cin >> passwrd; cout << "\n";

			NewData.open("database.txt", ios::app);
			if (NewData.is_open()) {
				NewData << login << " " << passwrd << " \n";
				cout << "Data saved to database\n";
				NewData.close();
			}
			else {
				cout << "Error with saving data\n";
			}
			cout << "Successfully created account\n";

			break;

		case 3:
			menu = false;
			break;
		default:
			cout << "Choose 1-2 option";
			break;
		}
	} while (menu);
}