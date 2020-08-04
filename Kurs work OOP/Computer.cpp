#include"Computer.h"

void ComputerDepartment::redactLaptop()
{
	size_t id;
	Laptop newlaptop;
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
						cin >> newlaptop.priceUSD;
					} while (newlaptop.priceUSD <= 0);
					it->priceUSD = newlaptop.priceUSD;
					it->priceUAH = it->priceUSD * rate;

					break;
				case 2:
					cout << "Enter new count on the stock->";
					cin >> newlaptop.CountInStock;
					it->CountInStock = newlaptop.CountInStock;
					break;
				case 3:
					cout << "Enter new characteristic->";
					cin.ignore(cin.rdbuf()->in_avail());
					getline(cin, newlaptop.characteristic);
					it->characteristic = newlaptop.characteristic;

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

void ComputerDepartment::redactPrinter()
{
	size_t id;
	Printer newprinter;
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
						cin >> newprinter.priceUSD;
					} while (newprinter.priceUSD <= 0);
					it->priceUSD = newprinter.priceUSD;
					it->priceUAH = it->priceUSD * rate;

					break;
				case 2:
					cout << "Enter new count on the stock->";
					cin >> newprinter.CountInStock;
					it->CountInStock = newprinter.CountInStock;
					break;
				case 3:
					cout << "Enter new characteristic->";
					cin.ignore(cin.rdbuf()->in_avail());
					getline(cin, newprinter.characteristic);
					it->characteristic = newprinter.characteristic;

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
