#include "TransactionManager.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
void TransactionManager::add() {
	Transaction t;
	
	t.nhap();
	t.setId(nextId);
	nextId++;
	transactions.push_back(t);
	
}
void TransactionManager::xoa() {
	
	int target;
	cin >> target;
	for (int i = 0; i < transactions.size(); i++) {
		if (transactions[i].id == target) {
			transactions.erase(transactions.begin() + i);
			break;
		}
	}
}
void TransactionManager::sua(int target) {
	for (int i = 0; i < transactions.size(); i++) {
		if (transactions[i].id == target) {
			cin.ignore();
			cout << "Nhap title moi: ";
			getline(cin, transactions[i].title);

			cout << "Nhap amount moi: ";
			cin >> transactions[i].amount;

			cin.ignore();

			cout << "Nhap category moi: ";
			getline(cin, transactions[i].category);

			cout << "Nhap date moi: ";
			getline(cin, transactions[i].date);

			cout << "Nhap type moi: ";
			getline(cin, transactions[i].type);

			break;
		}
	}
}
void TransactionManager::thongketieu() {
	double tong = 0;
	for (int i = 0; i < transactions.size(); i++) {
		if (transactions[i].type == "Expense") {
			tong += transactions[i].amount;
		}
	}
	cout << tong << endl;
}
void TransactionManager::thongkeluong() {
	double tong = 0;
	for (int i = 0; i < transactions.size(); i++) {
		if (transactions[i].type == "Income") {
			tong += transactions[i].amount;
		}
	}
	cout << tong << endl;
}
void TransactionManager::sort(int choice) {

	cout << "1. sort by id" << endl;
	cout << "2. sort by cost" << endl;
	cout << "3. sort by date" << endl;
	switch (choice) {
	case 1: {
		
		for (int i = 0; i < transactions.size(); i++) {
			for (int j = i + 1; j < transactions.size(); j++) {
				if (transactions[i].id < transactions[j].id) {
					swap(transactions[i], transactions[j]);
				}
			}
		}
	}
		  break;
	case 2: {
		for (int i = 0; i < transactions.size(); i++) {
			for (int j = i + 1; j < transactions.size(); j++) {
				if (transactions[i].amount < transactions[j].amount) {
					swap(transactions[i], transactions[j]);
				}
			}
		}
	}break;
	case 3: {
		for (int i = 0; i < transactions.size(); i++) {
			for (int j = i + 1; j < transactions.size(); j++) {
				if (transactions[i].date < transactions[j].date) {
					swap(transactions[i], transactions[j]);
				}
			}
		}
	}break;
	default: {
		return;
	}
	}
}
void TransactionManager::savetoFile() {
	{
		ofstream fout("data.txt");

		for (int i = 0; i < transactions.size(); i++)
		{
			fout << transactions[i].id << "|"
				<< transactions[i].title << "|"
				<< transactions[i].amount << "|"
				<< transactions[i].category << "|"
				<< transactions[i].date << "|"
				<< transactions[i].type << endl;
		}

		fout.close();
	}
}
void TransactionManager::loadfromFile() {
	transactions.clear();
	ifstream fin("data.txt");
	if (!fin) {
		return;
	}
	string line;
	while (getline(fin, line)) {
		stringstream ss(line);
		Transaction t;
		string token;
		getline(ss, token, '|');
		t.id = stoi(token);
		getline(ss, token, '|');
		t.title = token;

		getline(ss, token, '|');
		t.amount = stod(token);
		getline(ss, token, '|');
		t.category = token;
		getline(ss, token, '|');
		t.date = token;
		getline(ss, token, '|');
		t.type = token;
		transactions.push_back(t);
	}
	fin.close();
	nextId = getnextid();
}
int TransactionManager::getnextid() {
	if (transactions.empty()) 
		return 1;
	int maxid = transactions[0].id;
	for (int i = 0; i < transactions.size(); i++) {
		if (transactions[i].id > maxid) {
			maxid = transactions[i].id;
		}
	}
	return maxid + 1;
}
void TransactionManager::displayall() {
	for (int i = 0; i < transactions.size(); i++) {
		cout << transactions[i].title << endl
			<< transactions[i].id << endl
			<< transactions[i].amount << endl
			<< transactions[i].category << endl
			<< transactions[i].date << endl
			<< transactions[i].type << endl;
	}
}