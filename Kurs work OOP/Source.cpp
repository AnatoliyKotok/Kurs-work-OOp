#include<iostream>
#include<string>
#include"Menu.h"
#include"Computer.h"


using namespace std;
const string alogin= "admin";
const string apassword = "admin";
int main() {
	ComputerDepartment  cd;
	try {
		cd.readComp();
		cd.readLaptop();
		cd.readPrinter();
	}
	catch (exception & ex) {
		cout << ex.what() << endl;

	}
	
	Menu m;
	int action;
	string login;
	string password;
	do {
		cout << "1.Addmin" << endl;
		cout << "2.User" << endl;
		cout << "Select action->";
		cin >> action;
		system("cls");
		switch (action) {
		case 1:
			cout << "Enter login->";
			cin >> login;
			cout << "Enter password->";
			cin >> password;
			if (login == alogin && password == apassword) {
				m.AdminManu();
			}
			else {
				cout << "Incorect password or login" << endl;
				Sleep(1300);
				system("cls");
			}
			break;
		case 2:
			m.UserMenu();
			break;
		}
	} while (action != 3);
}