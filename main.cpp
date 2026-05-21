#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <queue>

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

void addRandomCustomer(Node*& front, Node*& back,
                       string names[], string drinks[]);

void addRandomMuffinCustomer(deque<Node>& muffinLine,
                             string names[], string muffins[]);

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

    string muffins[SIZE_ARR] {
        "Blueberry Muffin", "Chocolate Chip Muffin", "Banana Nut Muffin",
        "Lemon Poppy Muffin", "Bran Muffin", "Pumpkin Muffin",
        "Apple Cinnamon Muffin", "Double Chocolate Muffin",
        "Raspberry Muffin", "Corn Muffin"
    };

    Node* front{};
    Node* back{};

    deque<Node> muffinLine;

    for (int i{0}; i < START_CUSTOMERS; ++i) {
        addRandomCustomer(front, back, names, drinks);
        addRandomMuffinCustomer(muffinLine, names, muffins);
    }

    for (int numRound{1}; numRound <= MAX_ROUNDS; ++numRound) {
        if (front != nullptr) {
            cout << "Served: " << front->name << ": "
                               << front->drinkOrder << '\n';
            Node* temp{front};
            front = front->next;
            delete temp;

            if (front == nullptr) {
                back = nullptr;
            }
        } else {
            cout << "No customer served.\n";
        }

        if (rand() % 2 == 0) { // 50
            addRandomCustomer(front, back, names, drinks);
            cout << "New customer joined\n";
        } else {
            cout << "No new custmer joined\n";
        }

        if (!muffinLine.empty()) {
            cout << "Muffin served: " << muffinLine.front().name << ":"
                 << muffinLine.front().drinkOrder << '\n';

            muffinLine.pop_front();
        } else {
            cout << ""
        }
    }

    return 0;
}

void addRandomCustomer(Node*& front, Node*& back,
                       string names[], string drinks[]) {
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

void addRandomMuffinCustomer(deque<Node>& muffinLine,
                             string names[], string muffins[]) {
    Node muffinCustomer;
    muffinCustomer.name = names[rand() % SIZE_ARR];
    muffinCustomer.drinkOrder = muffins[rand() % SIZE_ARR];
    muffinCustomer.next = nullptr;

    muffinLine.push_back(muffinCustomer);
}