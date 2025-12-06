#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <string>

using namespace std;



int main() {
    string line;

    // Masukin data
    ofstream databaseMasuk("database.txt");
    string username, password;
    cout << "Username: ";
    cin >> username;
    databaseMasuk << (databaseMasuk, username);
    cout << "Password: ";
    cin >> password;
    databaseMasuk << (databaseMasuk, password);

    databaseMasuk.close();

    //Tampilin data
    ifstream databaseKeluar("database.txt");
    while (getline (databaseKeluar, line)) {
        cout << line << '\n';
    }
    databaseKeluar.close();
    return 0;
}