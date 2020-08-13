#pragma once
#include"Computer.h"
using namespace std;

class Menu {
    ComputerDepartment cd;
	int action;
public:
	void AdminManu() {
		
		do {
			cout << "1.Comp" << endl;
			cout << "2.Laptop" << endl;
			cout << "3.Printer" << endl;
			cout << "4.Print all" << endl;
			cout << "5.Sample" << endl;
			cout << "6.Exit" << endl;
			cout << "Select action->";
			cin >> action;
			system("cls");
			switch (action)
			{
			case 1:
				int a;
				do {
					cout << "1.Add comp" << endl;
					cout << "2.Print comp" << endl;
					cout << "3.Found comp" << endl;
					cout << "4.Redact comp" << endl;
					cout << "5.Delete comp" << endl;
					cout << "6.Exit" << endl;
					cout << "Select action->";
					cin >> a;
					system("cls");
					switch (a)
					{
					case 1:
						try {
							cd.addComp();
						}
						catch (exception & ex) {
							cout << ex.what() << endl;
						}
						break;
					case 2:
						cd.printComp();
						break;
					case 3:
						cd.foundComp();
						break;
					case 4:
						cd.redactComp();
						break;
					case 5:
						cd.delComp();
						break;
					}
				} while (a != 6);
				break;
			case 2:
				int l;
				do {
					cout << "1.Add laptop" << endl;
					cout << "2.Print laptop" << endl;
					cout << "3.Found laptop" << endl;
					cout << "4.Redact laptop" << endl;
					cout << "5.Delete laptop" << endl;
					cout << "6.Exit" << endl;
					cout << "Select action->";
					cin >> l;
					system("cls");
					switch (l)
					{
					case 1:
						try {
							cd.addLaptop();
						}
						catch (exception & ex) {
							cout << ex.what() << endl;
						}
						break;
					case 2:
						cd.printLaptop();
						break;
					case 3:
						cd.foundLaptop();
						break;
					case 4:
						cd.redactLaptop();
						break;
					case 5:
						cd.delLaptop();
						break;

					}
				} while (l != 6);
				break;
			case 3:
				int p;
				do {
					cout << "1.Add printer" << endl;
					cout << "2.Print printer" << endl;
					cout << "3.Found printer" << endl;
					cout << "4.Redact printer" << endl;
					cout << "5.Delete printer" << endl;
					cout << "6.Exit" << endl;
					cout << "Select action->";
					cin >> p;
					system("cls");
					switch (p)
					{
					case 1:
						try {
							cd.addPrinter();
						}
						catch (exception & ex) {
							cout << ex.what() << endl;
						}
						break;
					case 2:
						cd.printPrinter();
						break;
					case 3:
						cd.foundPrinters();
						break;
					case 4:
						cd.redactPrinter();
						break;
					case 5:
						cd.delPrinter();
						break;
					}
				} while (p != 6);
				break;
			case 4:
				cd.printAll();
				break;
			case 5:
				cd.Sample();
				break;

			}
		} while (action != 6);
	}
	void UserMenu() {
		int action;
		do {
			cout << "1.Comp" << endl;
			cout << "2.Laptop" << endl;
			cout << "3.Printer" << endl;
			cout << "4.Exit" << endl;
			cout << "Select section->";
			cin >> action;
			system("cls");
			switch (action) {
			case 1:
				cd.manuComp();
				break;
			case 2:
				cd.manuLaptop();
				break;
			case 3:
				cd.manuPrinter();
				break;
			}
		} while (action != 4);
		
	}
};