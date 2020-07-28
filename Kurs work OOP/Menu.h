#pragma once
#include<iostream>
#include<string>
#include<list>
#include<fstream>
#include<ctime>
#include"Computer.h"
using namespace std;

class Menu {
	ComputerDepartment cd;
	int action;
public:
	void manu() {
		/*try {
			cd.readComp();
			cd.readLaptop();
			cd.readPrinter();
		}
		catch (exception & ex) {
			cout << ex.what() << endl;
		}*/
		do {
			cout << "1.Comp" << endl;
			cout << "2.Laptop" << endl;
			cout << "3.Printer" << endl;
			cout << "4.Print all" << endl;
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
					}
				} while (a != 4);
				break;
			case 2:
				int l;
				do {
					cout << "1.Add laptop" << endl;
					cout << "2.Print laptop" << endl;
					cout << "3.Found laptop" << endl;
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
					}
				} while (l != 4);
			case 3:
				int p;
				do {
					cout << "1.Add printer" << endl;
					cout << "2.Print printer" << endl;
					cout << "3.Found printer" << endl;
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
					}
				} while (p != 4);
			case 4:
				cd.printAll();
				break;
			
			}
		} while (action != 5);
	}
};