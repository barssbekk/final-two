#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE_ARR{10};
const int NUM_CUSTOMERS{8};
const int START_CUSTOMERS{3};
const int MAX_ROUNDS{10};

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

    // //  cout << "Coffee booth line: \n";
    // Node* current{front};
    // while (current != nullptr) {
    //     cout << current->name << ": " << current->drinkOrder << '\n';
    //     current = current->next;
    // }

    for (int i{0}; i < START_CUSTOMERS; ++i) {
        int rndNameIndex{rand() % SIZE_ARR};
        int rndDrinkIndex{rand() % SIZE_ARR};

        Node* customer{new Node};
        customer->name = names[rndNameIndex];
        customer->drinkOrder = drinks[rndDrinkIndex];
        customer->next = nullptr;

        if (front == nullptr) {
            front = customer;
            back = customer;
        } else {
            back->next = customer;
            back = customer;
        }
    }

    for (int numRound{1}; numRound <= MAX_ROUNDS; ++numRound) {
        if (front != nullptr) {
            cout << "Served: " << front->name << ": "
                               << front->drinkOrder << '\n';
            Node* temp{front};
            front = front->next;
            if (front == nullptr)
                back = nullptr;
        } else {
            cout << "No customer served.\n";
        }

        if (rand() % 2 == 0) {
            int rndNameIndex{rand() % SIZE_ARR};
            int rndDrinkIndex{rand() % SIZE_ARR};
        }
    }

    return 0;
}

void addRandomCustomer(Node* front, Node*& back,
                       string names[], string drinks[]) {
    int rndNameIndex{rand() % SIZE_ARR};
    int rndDrinkIndex{rand() % SIZE_ARR};

    Node* customer{new Node};
    customer->name = names[rndNameIndex];
    customer->drinkOrder = drinks[rndDrinkIndex];
    customer->next = nullptr;
}