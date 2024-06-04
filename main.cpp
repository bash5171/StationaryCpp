#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Sta {
    string name;
    int quantity;
    double price;
};

void addSta() {
    Sta sta;
    cout << "Enter stationery name: ";
    cin >> sta.name;
    cout << "Enter quantity: ";
    cin >> sta.quantity;
    cout << "Enter price: ";
    cin >> sta.price;

    ofstream file("stadb.txt", ios::app);
    file << sta.name << " " << sta.quantity << " " << sta.price << endl;
    file.close();
}

void displaySta() {
    ifstream file("stadb.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}



void updateQuantity() {
    Sta stationery;
    fstream file, ftemp;
    string name;
    int quantity, count = 0;
    cout << "Enter stationery name: ";
    cin >> name;
    file.open("stadb.txt", ios::in);
    ftemp.open("temp.txt", ios::out | ios::app);
    if (!file) {
        cout << "Database Failed To Open!" << endl;
    } else {
        file >> sta.name >> sta.quantity >> sta.price;
        while(!file.eof()) {
            if (name == sta.name) {
                cout << "Enter new quantity: ";
                cin >> quantity;
                ftemp << sta.name << " " << quantity << " " << sta.price << endl;
                count = 1;
                cout << "Account Updated!" << endl;
            } else 
                ftemp << sta.name << " " << sta.quantity << " " << sta.price << endl;
                file >> sta.name >> sta.quantity >> sta.price; 
            
        } 
        if (count == 0) {
            cout << "Record Not Found!" << endl;
        }
    }
    system("pause");
    file.close();
    ftemp.close();
    remove("stadb.txt");
    rename("temp.txt", "stadb.txt");
}


int main() {
    int choice;
    while (true) {
        system("cls");
        cout << "Stationery Management System" << endl;
        cout << "1. Add New Stationery\n2. Display Stationery\n3. Update Quantity\n4. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                addSta();
                break;
            case 2:
                displaySta();
                break;
            case 3:
                updateQuantity();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}

