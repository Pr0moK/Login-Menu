#include <iostream>
#include <fstream>

std::ifstream OpenFile;
std::string datauser;
std::string logincheck, passwordcheck;
int pos,newline;
int dataTrue = 0;


void checkuser(std::string user,std::string pass) {
	OpenFile.open("database.txt");
	if (OpenFile.is_open()) {
		while (getline(OpenFile, datauser))
		{

			pos = datauser.find(" ");
			newline = datauser.find("\n");
			logincheck = datauser.substr(0, pos);
			passwordcheck = datauser.substr(pos+1);
			passwordcheck.pop_back();
			if (logincheck == user && passwordcheck == pass) {
					dataTrue = 1;
					std::cout << "Data is correct, Welcome!\n";
					break;
			}

		}
		if (dataTrue == 0) {
		std::cout << "Data is wrong, try again\n";
		}
		OpenFile.close();
	}

}