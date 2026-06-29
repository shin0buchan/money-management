#pragma once
#include <iostream>
#include <vector>
#include "Transaction.h"
using namespace std;
class TransactionManager {
public:
  
        vector<Transaction> transactions;
        int nextId;
        
    
    void add();
    int getnextid();
    void displayall();
    void savetoFile();
    void sort(int choice);
    void loadfromFile();
    void xoa();
    void sua(int target);
    void thongkeluong();
    void thongketieu();
};