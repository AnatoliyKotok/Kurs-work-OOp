#pragma once
#include<iostream>
#include<string>
#include<list>
#include<fstream>
using namespace std;
const string fname= "Comp.txt";
const string flaptop = "Laptop.txt";
const string fprint = "Print.txt";
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
	size_t CountInStock;
	friend ostream& operator<<(ostream& out, const Item& comp);
	friend istream& operator>>(istream& in, Item& comp);
	void print()const {
		cout << "Price in USD->" << priceUSD << endl;
		cout << "Price in UAH->" << priceUAH << endl;
		cout << "Count in stock->" << CountInStock << endl;
		cout << "Mark->" << name << endl;
		cout << "Characteristic->" << characteristic << endl;
		cout << endl;
	}
};
ostream& operator<<(ostream& out,const Item&comp) {
	out << comp.priceUSD << "\n" << comp.priceUAH << "\n" << comp.CountInStock << "\n" << comp.name << "\n" << comp.characteristic << endl;
	return out;
}
 istream& operator>>(istream& in, Item& comp)
{
	in >> comp.priceUSD;
	in >> comp.priceUAH;
	in >> comp.CountInStock;
	in >> comp.name;
	in >> comp.characteristic;
	return in;
}
class Computer :public Item, public Rate {
	
};
class Laptop:public Item,public Rate
{

};
class Printer :public Item, public Rate {

};
class ComputerDepartment:public Rate {
	list<Computer>comps;
	list<Laptop>laptops;
	list<Printer>printers;
public:
	void addComp() {
		Computer comp;
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
			if (name == it->name && minPrice == it->priceUSD||maxPrice==it->priceUSD) {
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
		cout << "Enter mark comp->";
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, name);
		cout << "Price from->";
		cin >> minPrice;
		cout << "Price to->";
		cin >> maxPrice;
		bool found = false;
		for (auto it = laptops.begin(); it != laptops.end(); it++) {
			if (name == it->name && minPrice == it->priceUSD || maxPrice == it->priceUSD) {
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
		cout << "Enter mark comp->";
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, name);
		cout << "Price from->";
		cin >> minPrice;
		cout << "Price to->";
		cin >> maxPrice;
		bool found = false;
		for (auto it = printers.begin(); it != printers.end(); it++) {
			if (name == it->name && minPrice == it->priceUSD || maxPrice == it->priceUSD) {
				it->print();
				found = true;

			}
		}
		if (found == false) {
			cout << "Serch result:0" << endl;
		}
	}

};