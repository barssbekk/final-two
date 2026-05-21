#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE_ARR{10};
const int  NUM_CUSTOMERS{8};

struct Node {
    string name;
    string drinkOrder;
    Node* next;
};

int main() {
    srand(time(nullptr));
    string names[SIZE_ARR] {
        "Alex", "Jordan", "Taylor", "Morgan", "Casey",
        "Riley", "Jamie", "Avery", "Cameron", "Reese"
    };

    string drinks[SIZE_ARR] {
        "Latte", "Cappuccino", "Americano", "Mocha", "Espresso",
        "Cold Brew", "Iced Coffee", "Macchiato", "Chai Latte", "Hot Chocolate"
    };

    Node* front{};
    Node* back{};

    int rndNameIndex { rand() % SIZE_ARR };
    int rndDrinkIndex { rand() % SIZE_ARR};
    cout << names[rndNameIndex] << ": " << drinks[rndDrinkIndex] << '\n';

    for (int i{0}; i < NUM_CUSTOMERS; ++i) {
        int rndNameIndex{rand() % SIZE_ARR};
        int rndDrinkIndex{rand() % SIZE_ARR};

        Node* customer{new Node};
        customer->name = names[rndNameIndex];
        customer->drinkOrder = drinks[rndDrinkIndex];

        if (front == nullptr) {
            front = customer;
            back = customer;
        }
    }

    return 0;
}