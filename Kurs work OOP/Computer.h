#pragma once
#include<iostream>
#include<string>
#include<list>
#include<fstream>
#include<ctime>
#include<windows.h>
using namespace std;
const string fname= "Comp.txt";
const string flaptop = "Laptop.txt";
const string fprint = "Print.txt";
double yourMoney = 0;
class Rate {
protected:
	double rate = 27.50;
};
class Item {

public:
	string name;
	string characteristic;
	double priceUSD;
	double priceUAH;
	size_t id;
	size_t CountInStock;
	friend ostream& operator<<(ostream& out, const Item& comp);
	friend istream& operator>>(istream& in, Item& comp);
	void print()const {
		cout << "Price in USD->" << priceUSD << endl;
		cout << "Price in UAH->" << priceUAH << endl;
		cout << "Count in stock->" << CountInStock << endl;
		cout << "Mark->" << name << endl;
		cout << "Characteristic->" << characteristic << endl;
		cout << "ID->" << id << endl;
		cout << endl;
	}
	
};
ostream& operator<<(ostream& out,const Item&comp) {
	out << comp.priceUSD << "\n" << comp.priceUAH << "\n" << comp.CountInStock << "\n" << comp.name << "\n" << comp.characteristic <<"\n"<<comp.id <<endl;
	return out;
}
 istream& operator>>(istream& in, Item& comp)
{
	in >> comp.priceUSD;
	in >> comp.priceUAH;
	in >> comp.CountInStock;
	in >> comp.name;
	in >> comp.characteristic;
	in >> comp.id;
	return in;
}
class Computer :public Item, public Rate {
	
};
class Laptop:public Item,public Rate
{

};
class Printer :public Item, public Rate {

};
class ComputerDepartment:public Rate{
protected:
	list<Computer>comps;
	list<Laptop>laptops;
	list<Printer>printers;
public:
	void addComp() {
		Computer comp;
		size_t id;
		cout << "Enter price in USD->";
		do {
			cin >> comp.priceUSD;
		} while (comp.priceUSD < 0);
		comp.priceUAH = comp.priceUSD * rate;
		cout << "Enter count in ctock->";
		cin >> comp.CountInStock;
		cout << "Enter mark->";
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, comp.name);
		cout << "Enter characteristic->";
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, comp.characteristic);
		agin:
		cout << "Enter id->";
		cin >> id;
		for (auto it : comps) {
			if (id == it.id) {
				goto agin;
				break;
			}
		}
		comp.id = id;
		comps.push_back(comp);
		ofstream fout;
		fout.open(fname, ios::app);
		if (!fout.is_open()) {
			throw exception("Error:file not open");
		}
		else {
			fout << comp;
		}
	}
	void readComp() {
		Computer comp;
		ifstream fin;
		fin.open(fname);
		if (!fin.is_open()) {
			throw exception("Error:file not open");
		}
		else {
			    fin >> comp;
			while (!fin.eof()) {
				comps.push_back(comp);
				fin >> comp;
			}

		}
	}
	void printComp() {
		comps.sort([](const Computer& a, const Computer& b) {return a.name < b.name; });
		int i = 0;
		for (auto el : comps) {
			cout << ++i << ")";
			el.print();
		}
	}
	void addLaptop() {
		Laptop laptop;
		size_t id;
		cout << "Enter price in USD->";
		do {
			cin >> laptop.priceUSD;
		} while (laptop.priceUSD < 0);
		laptop.priceUAH = laptop.priceUSD * rate;
		cout << "Enter count in ctock->";
		cin >> laptop.CountInStock;
		cout << "Enter mark->";
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, laptop.name);
		cout << "Enter characteristic->";
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, laptop.characteristic);
	agin:
		cout << "Enter id->";
		cin >> id;
		for (auto it : laptops) {
			if (id == it.id) {
				goto agin;
				break;
			}
		}
		laptop.id = id;
		laptops.push_back(laptop);
		ofstream fout;
		fout.open(flaptop, ios::app);
		if (!fout.is_open()) {
			throw exception("Error:file not open");
		}
		else {
			fout << laptop;
		}
	}
	void readLaptop() {
		Laptop laptop;
		ifstream fin;
		fin.open(flaptop);
		if (!fin.is_open()) {
			throw exception("Error:file not open");
		}
		else {
			fin >> laptop;
			while (!fin.eof()) {
				laptops.push_back(laptop);
				fin >> laptop;
			}

		}
	}
	void printLaptop() {
		laptops.sort([](const Laptop& a, const Laptop& b) {return a.name < b.name; });
		int i = 0;
		for (auto el : laptops) {
			cout << ++i << ")";
			el.print();
		}
	}
	void addPrinter() {
		Printer printer;
		size_t id;
		cout << "Enter price in USD->";
		do {
			cin >> printer.priceUSD;
		} while (printer.priceUSD < 0);
		printer.priceUAH = printer.priceUSD * rate;
		cout << "Enter count in ctock->";
		cin >> printer.CountInStock;
		cout << "Enter mark->";
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, printer.name);
		cout << "Enter characteristic->";
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, printer.characteristic);
	agin:
		cout << "Enter id->";
		cin >> id;
		for (auto it : printers) {
			if (id == it.id) {
				goto agin;
				break;
			}
		}
		printer.id = id;
		printers.push_back(printer);
		ofstream fout;
		fout.open(fprint, ios::app);
		if (!fout.is_open()) {
			throw exception("Error:file not open");
		}
		else {
			fout << printer;
		}
	}
	void readPrinter() {
		Printer printer;
		ifstream fin;
		fin.open(fprint);
		if (!fin.is_open()) {
			throw exception("Error:file not open");
		}
		else {
			fin >> printer;
			while (!fin.eof()) {
				printers.push_back(printer);
				fin >>printer;
			}

		}
	}
	void printPrinter() {
		printers.sort([](const Printer& a, const Printer& b) {return a.name < b.name; });
		int i = 0;
		for (auto el : printers) {
			cout << ++i << ")";
			el.print();
		}
	}
	void printAll() {
		cout << "Computers:" << endl;
		printComp();
		cout << endl;
		cout << "Laptops:" << endl;
		printLaptop();
		cout << endl;
		cout << "Printers:" << endl;
		printPrinter();
	}
	void foundComp() {
		double minPrice = 0;
		double maxPrice = 0;
		string name;
		cout << "Enter mark comp->";
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, name);
		cout << "Price from->";
		cin >> minPrice;
		cout << "Price to->";
		cin >> maxPrice;
		bool found = false;
		for (auto it = comps.begin(); it != comps.end(); it++) {
			if (name == it->name && minPrice <= it->priceUSD&&maxPrice>=it->priceUSD) {
				    it->print();
					found = true;
				
			}
		}
		if (found == false) {
			cout << "Serch result:0" << endl;
		}
	}
	void foundLaptop() {
		double minPrice = 0;
		double maxPrice = 0;
		string name;
		cout << "Enter mark laptop->";
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, name);
		cout << "Price from->";
		cin >> minPrice;
		cout << "Price to->";
		cin >> maxPrice;
		bool found = false;
		for (auto it = laptops.begin(); it != laptops.end(); it++) {
			if (name == it->name && minPrice <= it->priceUSD &&maxPrice >= it->priceUSD) {
				it->print();
				found = true;

			}
		}
		if (found == false) {
			cout << "Serch result:0" << endl;
		}
	}
	void foundPrinters() {
		double minPrice = 0;
		double maxPrice = 0;
		string name;
		cout << "Enter mark print->";
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, name);
		cout << "Price from->";
		cin >> minPrice;
		cout << "Price to->";
		cin >> maxPrice;
		bool found = false;
		for (auto it = printers.begin(); it != printers.end(); it++) {
			if (name == it->name && minPrice <= it->priceUSD && maxPrice >= it->priceUSD) {
				it->print();
				found = true;

			}
		}
		if (found == false) {
			cout << "Serch result:0" << endl;
			Sleep(1100);
			system("cls");
		}
	}
	void redactComp() {
		size_t idc;
		double price;
		size_t count;
		string characteristic;
		int action;
		bool found = false;
		cout << "Enter id comp for redact->";
		cin >> idc;
        for (auto it = comps.begin(); it != comps.end(); it++) {
			if (idc == it->id) {
				found == true;
				do {
					it->print();
					cout << "1.Redact price" << endl;
					cout << "2.Redact count" << endl;
					cout << "3.Redact characteristic" << endl;
					cout << "4.Exit" << endl;
					cout << "Select action->";
					cin >> action;
					system("cls");
					switch (action) {
					case 1:

						cout << "Enter new price->";
						do {
							cin >> price;
						} while (price <= 0);
							it->priceUSD = price;
						it->priceUAH = it->priceUSD * rate;

						break;
					case 2:
						cout << "Enter new count on the stock->";
						cin >> count;
						it->CountInStock = count;
						break;
					case 3:
						cout << "Enter new characteristic->";
						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, characteristic);
						it->characteristic =characteristic;

						break;
					}
				} while (action != 4);
				break;
			}
			if (found == false) {
				cout << "Comp not found" << endl;
				Sleep(1000);
				system("cls");
				return;
			}
		}
	}
	void redactLaptop()
	{
		size_t id;
		double price;
		size_t count;
		string characteristic;
		int action;
		bool found = false;
		cout << "Enter id comp for redact->";
		cin >> id;
		for (auto it = laptops.begin(); it != laptops.end(); it++) {
			if (id == it->id) {
				found == true;
				do {
					it->print();
					cout << "1.Redact price" << endl;
					cout << "2.Redact count" << endl;
					cout << "3.Redact characteristic" << endl;
					cout << "4.Exit" << endl;
					cout << "Select action->";
					cin >> action;
					system("cls");
					switch (action) {
					case 1:

						cout << "Enter new price->";
						do {
							cin >> price;
						} while (price <= 0);
						it->priceUSD = price;
						it->priceUAH = it->priceUSD * rate;

						break;
					case 2:
						cout << "Enter new count on the stock->";
						cin >> count;
						it->CountInStock = count;
						break;
					case 3:
						cout << "Enter new characteristic->";
						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, characteristic);
						it->characteristic = characteristic;

						break;
					}
				} while (action != 4);
				break;
			}
			if (found == false) {
				cout << "Laptop not found" << endl;
				Sleep(1000);
				system("cls");
				return;
			}
		}
	}
	void redactPrinter()
	{
		size_t id;
		double price;
		size_t count;
		string characteristic;
		int action;
		bool found = false;
		cout << "Enter id comp for redact->";
		cin >> id;
		for (auto it = printers.begin(); it != printers.end(); it++) {
			if (id == it->id) {
				found == true;
				do {
					it->print();
					cout << "1.Redact price" << endl;
					cout << "2.Redact count" << endl;
					cout << "3.Redact characteristic" << endl;
					cout << "4.Exit" << endl;
					cout << "Select action->";
					cin >> action;
					system("cls");
					switch (action) {
					case 1:

						cout << "Enter new price->";
						do {
							cin >> price;
						} while (price <= 0);
						it->priceUSD = price;
						it->priceUAH = it->priceUSD * rate;

						break;
					case 2:
						cout << "Enter new count on the stock->";
						cin >> count;
						it->CountInStock = count;
						break;
					case 3:
						cout << "Enter new characteristic->";
						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, characteristic);
						it->characteristic = characteristic;

						break;
					}
				} while (action != 4);
				break;
			}
			if (found == false) {
				cout << "Printer not found" << endl;
				Sleep(1000);
				system("cls");
				return;
			}
		}
	}
	void delComp() {
		size_t id;
		bool found=false;
		cout << "Enter comp id for delete it->";
		cin >> id;
		for (auto it = comps.begin(); it != comps.end(); it++) {
			if (id == it->id) {
				found = true;
				comps.erase(it);
				cout << "Comp was deleted sucsesful" << endl;
				Sleep(1200);
				system("cls");
				return;
			}
		}
		if (found == false) {
			cout << "Comp with this id not found" << endl;
			Sleep(1200);
			system("cls");
			return;
		}
	}
	void delLaptop() {
		size_t id;
		bool found = false;
		cout << "Enter comp id for delete it->";
		cin >> id;
		for (auto it = laptops.begin(); it != laptops.end(); it++) {
			if (id == it->id) {
				found = true;
				laptops.erase(it);
				cout << "Laptop was deleted sucsesful" << endl;
				Sleep(1200);
				system("cls");
				return;
			}
		}
		if (found == false) {
			cout << "Laptop with this id not found" << endl;
			Sleep(1200);
			system("cls");
			return;
		}
	}
	void delPrinter() {
		size_t id;
		bool found = false;
		cout << "Enter comp id for delete it->";
		cin >> id;
		for (auto it = printers.begin(); it != printers.end(); it++) {
			if (id == it->id) {
				found = true;
				printers.erase(it);
				cout << "Priner was deleted sucsesful" << endl;
				Sleep(1200);
				system("cls");
				return;
			}
		}
		if (found == false) {
			cout << "Printer with this id not found" << endl;
			Sleep(1200);
			system("cls");
			return;
		}
	}
	void Sample() {
		cout << "Goods whose price is less than 300 or which is lass than 5 pieces" << endl;
		int maxPrice=300;
		int minCount = 5;
		for (auto it = comps.begin(); it != comps.end(); it++) {
			if (it->priceUSD <= maxPrice||it->CountInStock<=minCount) {
				it->print();
			}
		}
		for (auto it = laptops.begin(); it != laptops.end(); it++) {
			if (it->priceUSD <= maxPrice || it->CountInStock <= minCount) {
				it->print();
			}
		}
		for (auto it = printers.begin(); it != printers.end(); it++) {
			if (it->priceUSD <= maxPrice || it->CountInStock <= minCount) {
				it->print();
			}
		}
	}
	void putMoney() {
		cout << "Put money on your accaunt->";
		double money;
		cin >> money;
		yourMoney = money;
	}
	void buyComp(){
		foundComp();
		size_t id;
		cout << "Enter comp id for buy it->";
		cin >> id;
		cout << "Enter count comp what you want buy->";
		size_t count;
		cin >> count;
		bool fid = false;
		bool fcount = false;
		bool fmoney = false;
		for (auto it = comps.begin(); it != comps.end(); it++) {
			if (id == it->id) {
				fid = true;
				if (count <= it->CountInStock) {
					fcount = true;
					double price = count * it->priceUSD;
					if (yourMoney >= price) {
						fmoney = true;
						it->CountInStock -= count;
						yourMoney -= price;
						if (it->CountInStock == 0) {
							comps.erase(it);
							return;
						}
					}
				}
				break;
			}
		}
		if (fid == false) {
			cout << "Incorect id" << endl;
			Sleep(1300);
			system("cls");
		}
		if (fcount == false) {
			cout << "No enough computers" << endl;
			Sleep(1300);
			system("cls");
		}
		if (fmoney == false) {
			cout << "No enough money" << endl;
			Sleep(1300);
			system("cls");
		}
	}
	void buyLaptop(){
		foundLaptop();
		size_t id;
		cout << "Enter laptop id for buy it->";
		cin >> id;
		cout << "Enter count laptops what you want buy->";
		size_t count;
		cin >> count;
		bool fid = false;
		bool fcount = false;
		bool fmoney = false;
		for (auto it = laptops.begin(); it != laptops.end(); it++) {
			if (id == it->id) {
				fid = true;
				if (count <= it->CountInStock) {
					fcount = true;
					double price = count * it->priceUSD;
					if (yourMoney >= price) {
						fmoney = true;
						it->CountInStock -= count;
						yourMoney -= price;
						if (it->CountInStock == 0) {
							laptops.erase(it);
							return;
						}
					}
				}
				break;
			}
		}
		if (fid == false) {
			cout << "Incorect id" << endl;
			Sleep(1300);
			system("cls");
		}
		if (fcount == false) {
			cout << "No enough laptops" << endl;
			Sleep(1300);
			system("cls");
		}
		if (fmoney == false) {
			cout << "No enough money" << endl;
			Sleep(1300);
			system("cls");
		}
	}
	void buyPrinter() {
		foundPrinters();
		size_t id;
		cout << "Enter printer id for buy it->";
		cin >> id;
		cout << "Enter count printers what you want buy->";
		size_t count;
		cin >> count;
		bool fid = false;
		bool fcount = false;
		bool fmoney = false;
		for (auto it = printers.begin(); it != printers.end(); it++) {
			if (id == it->id) {
				fid = true;
				if (count <= it->CountInStock) {
					fcount = true;
					double price = count * it->priceUSD;
					if (yourMoney >= price) {
						fmoney = true;
						it->CountInStock -= count;
						yourMoney -= price;
						if (it->CountInStock == 0) {
							printers.erase(it);
							return;
						}
					}
				}
				break;
			}
		}
		if (fid == false) {
			cout << "Incorect id" << endl;
			Sleep(1300);
			system("cls");
		}
		if (fcount == false) {
			cout << "No enough printers" << endl;
			Sleep(1300);
			system("cls");
		}
		if (fmoney == false) {
			cout << "No enough money" << endl;
			Sleep(1300);
			system("cls");
		}
	}
	void manuComp() {
		int action;
		do {
			cout << "Money->" << yourMoney << endl;
			cout << "1.Buy comp" << endl;
			cout << "2.Found comp" << endl;
			cout << "3.Print comp" << endl;
			cout << "4.Put money on account" << endl;
			cout << "5.Main manu" << endl;
			cout << "Select action->";
			cin >> action; system("cls");
			switch (action) {
			case 1:
				buyComp();
				break;
			case 2:
				foundComp();
				break;
			case 3:
				printComp();
				break;
			case 4:
				putMoney();
				break;
			}
		} while (action != 5);

	}
	void manuLaptop() {
		int action;
		do {
			cout << "Money->" << yourMoney << endl;
			cout << "1.Buy laptop" << endl;
			cout << "2.Found laptop" << endl;
			cout << "3.Print laptop" << endl;
			cout << "4.Put money on account" << endl;
			cout << "5.Main manu" << endl;
			cout << "Select action->";
			cin >> action; system("cls");
			switch (action) {
			case 1:
				buyLaptop();
				break;
			case 2:
				foundLaptop();
				break;
			case 3:
				printLaptop();
				break;
			case 4:
				putMoney();
				break;
			}
		} while (action != 5);

	}
	void manuPrinter() {
		int action;
		do {
			cout << "Money->" << yourMoney << endl;
			cout << "1.Buy printer" << endl;
			cout << "2.Found printer" << endl;
			cout << "3.Print printer" << endl;
			cout << "4.Put money on account" << endl;
			cout << "5.Main manu" << endl;
			cout << "Select action->";
			cin >> action; system("cls");
			switch (action) {
			case 1:
				buyPrinter();
				break;
			case 2:
				foundPrinters();
				break;
			case 3:
				printPrinter();
				break;
			case 4:
				putMoney();
				break;
			}
		} while (action != 5);

	}
};



