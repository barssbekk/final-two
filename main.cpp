#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
    string name;
    string drinkOrder;
    Node* next;
};

int main() {
    srand(time(nullptr));
    string names[] {
        "Alex", "Jordan", "Taylor", "Morgan", "Casey",
        "Riley", "Jamie", "Avery", "Cameron", "Reese"
    };

    string drinks[] {
        "Latte", "Cappuccino", "Americano", "Mocha", "Espresso",
        "Cold Brew", "Iced Coffee", "Macchiato", "Chai Latte", "Hot Chocolate"
    };

    Node* front{};
    Node* back{};

    int rndIndex { }

    return 0;
}