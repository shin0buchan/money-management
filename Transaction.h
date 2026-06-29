#pragma once
#include <string>
using namespace std;
class Transaction
{
public:
    string title;
    int id;
    double amount;
    string category;
    string date;
    string type; // Income hoặc Expense
    void nhap();
    void hienthi();
    void setId(int newId);
};