#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {
    unsigned quantity;
    string customer, product;
    map<string, map<string, long unsigned>> sales;
    while (cin >> customer) {
        cin >> product >> quantity;
        sales[customer][product] += quantity;
    }

    for (const auto& [customer, productQuantities] : sales) {
        cout << customer << ':' << endl;
        for (const auto& [product, quantity] : productQuantities) {
            cout << product << ' ' << quantity << endl;
        }
    }

    return EXIT_SUCCESS;
}