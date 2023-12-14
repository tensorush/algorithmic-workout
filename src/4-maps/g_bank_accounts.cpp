#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {
    int sum;
    unsigned percentage;
    map<string, int> accounts;
    string client_1, client_2, operation;
    while (cin >> operation) {
        if (operation == "DEPOSIT") {
            cin >> client_1 >> sum;
            accounts[client_1] += sum;
        } else if (operation == "WITHDRAW") {
            cin >> client_1 >> sum;
            accounts[client_1] -= sum;
        } else if (operation == "BALANCE") {
            cin >> client_1;
            if (accounts.contains(client_1))
                cout << accounts[client_1] << endl;
            else
                cout << "ERROR" << endl;
        } else if (operation == "TRANSFER") {
            cin >> client_1 >> client_2 >> sum;
            accounts[client_1] -= sum;
            accounts[client_2] += sum;
        } else if (operation == "INCOME") {
            cin >> percentage;
            for (auto& [client, balance] : accounts) {
                if (balance > 0)
                    balance += balance * percentage / 100;
            }
        }
    }

    return EXIT_SUCCESS;
}