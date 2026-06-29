#include "Transaction.h"
#include <iostream>
using namespace std;
void Transaction::nhap() {
    cout << "Nhap tieu de" << ""; cin.ignore(); getline(cin, title); cout << endl;

    cout << "Nhap gia tri" << ""; ; cin >> amount; cout << endl;
    cout << "Nhap danh muc" << ""; cin.ignore(); getline(cin, category); cout << endl;
    cout << "Nhap ngay" << ""; cin.ignore(); getline(cin, date); cout << endl;
    cout << "Nhap loai chi tieu" << ""; cin.ignore(); getline(cin, type); cout << endl;
}
void Transaction::hienthi()
{
    cout << id << " "
        << title << " "
        << amount << " "
        << category << " "
        << date << " "
        << type << endl;
}
void Transaction::setId(int newid) {
    id = newid;
}
