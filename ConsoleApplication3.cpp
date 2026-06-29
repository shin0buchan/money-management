#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "TransactionManager.h"
int main() {
    
    TransactionManager x;
    
    int choice;
    do {
        
        cout << "1. Them giao dich\n";
        cout << "2. Xem giao dich\n";
        cout << "3. Xoa giao dich\n";
        cout << "0. Sua giao dich\n";
        cout << "4. Thong ke tong chi\n";
        cout << "5. Thong ke tong thu\n";
        cout << "6. LuuFile\n";
        cout << "7. LoadFile\n";
        cout << "8. Sort\n";
        cout << "9. Thoat\n";
        


        cin >> choice;
        switch (choice) {
        case 1: {
            x.add();
           
            
           
        }
            break;
        case 2: {
            x.displayall();
        }
              break;
        case 3: {
            
            x.xoa();
        }
              break;
        case 0: {
            int target;
            cin >> target;
            x.sua(target);
        }break;
        case 4: {
            x.thongketieu();
        }
              break;
        case 5: {
            x.thongkeluong();
        }
              break;
        case 6: {
            x.savetoFile();
        }break;
        case 7: {
            
            x.loadfromFile();
            
        }break;
        case 8: {
            int choice;
            cin >> choice;
            x.sort(choice);

        }break;
        default: {
            return 0;
        }
        }
    } while (choice != 9);
}
