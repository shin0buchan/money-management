#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
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
public:
    void setId(int newId) {
        id = newId;
    }
    void nhap(){
        cout << "Nhap tieu de" << ""; cin.ignore(); getline(cin, title); cout << endl;
    
        cout << "Nhap gia tri" << ""; ; cin >> amount; cout << endl;
        cout << "Nhap danh muc"<<""; cin.ignore(); getline(cin, category); cout << endl;
        cout << "Nhap ngay"<<"";cin.ignore(); getline(cin, date); cout << endl;
        cout << "Nhap loai chi tieu"<<""; cin.ignore(); getline(cin, type); cout << endl;
       

    }
    void saveToFile(vector<Transaction>& x)
    {
        ofstream fout("data.txt");

        for (int i = 0; i < x.size(); i++)
        {
            fout << x[i].id << "|"
                << x[i].title << "|"
                << x[i].amount << "|"
                << x[i].category << "|"
                << x[i].date << "|"
                << x[i].type << endl;
        }

        fout.close();
    }
    void sort(vector<Transaction>& x, int choice) {
       
            cout << "1. sort by id" << endl;
            cout << "2. sort by cost" << endl;
            cout << "3. sort by date" << endl;
            switch (choice) {
            case 1: {
                
                for (int i = 0; i < x.size(); i++) {
                    for (int j = i + 1; j < x.size(); j++) {
                        if (x[i].id < x[j].id) {
                            swap(x[i], x[j]);
                        }
                    }
                }
            }
                  break;
            case 2: {
                for (int i = 0; i < x.size(); i++) {
                    for (int j = i + 1; j < x.size(); j++) {
                        if (x[i].amount < x[j].amount) {
                            swap(x[i], x[j]);
                        }
                    }
                }
            }break;
            case 3: {
                for (int i = 0; i < x.size(); i++) {
                    for (int j = i + 1; j < x.size(); j++) {
                        if (x[i].date < x[j].date) {
                            swap(x[i], x[j]);
                        }
                    }
                }
            }break;
            default:{
                      return;
                  }
            }
        } 
    
    void loadfromFile(vector<Transaction>& x) {
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
            x.push_back(t);
        }
        fin.close();
    }
    void hienthi(vector<Transaction>& x) {
        for (int i = 0; i < x.size(); i++) {
            cout << x[i].title << " " << x[i].id << " " << x[i].amount << " " << x[i].category << " " << x[i].date << " " << x[i].type << endl;
        }
    }
    void xoagiaodich(vector<Transaction>& x,int target){
        for (int i = 0; i < x.size(); i++) {
            if (x[i].id == target) {
                x.erase(x.begin() + i);
                break;
            }
        }
    }
    void sua(vector<Transaction>& x, int target) {
        for (int i = 0; i < x.size(); i++) {
            if (x[i].id == target) {
                cin.ignore();
                cout << "Nhap title moi: ";
                getline(cin, x[i].title);

                cout << "Nhap amount moi: ";
                cin >> x[i].amount;

                cin.ignore();

                cout << "Nhap category moi: ";
                getline(cin, x[i].category);

                cout << "Nhap date moi: ";
                getline(cin, x[i].date);

                cout << "Nhap type moi: ";
                getline(cin, x[i].type);

                break;
            }
        }
    }
    void thongketongchi(vector<Transaction>& x) {
        double tong = 0;
        for (int i = 0; i < x.size(); i++) {
            if (x[i].type == "Expense") {
                tong += x[i].amount;
            }
        }
        cout << tong << endl;
    }
    void thongketongthunhap(vector<Transaction>& x) {
        double tong = 0;
        for (int i = 0; i < x.size(); i++) {
            if (x[i].type == "Income") {
                tong += x[i].amount;
            }
        }
        cout << tong << endl;
    }
};
int main() {
    int nextId = 1;
    Transaction x;
    vector<Transaction> y;
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
            x.nhap(y);
            x.setId(nextId);
            nextId++;
            y.push_back(x);
        }
            break;
        case 2: {
            x.hienthi(y);
        }
              break;
        case 3: {
            int target;
            cin >> target;
            x.xoagiaodich(y,target);
        }
              break;
        case 0: {
            int target;
            cin >> target;
            x.sua(y, target);
        }break;
        case 4: {
            x.thongketongchi(y);
        }
              break;
        case 5: {
            x.thongketongthunhap(y);
        }
              break;
        case 6: {
            x.saveToFile(y);
        }
        case 7: {
            y.clear();
            x.loadfromFile(y);
        }
        case 8: {
            int choice;
            cin >> choice;
                x.sort(y, choice);
                
        }
        default: {
            return 0;
        }
        }
    } while (choice != 7);
}
