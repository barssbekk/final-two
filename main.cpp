#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <queue>
#include <vector>

using namespace std;

const int SIZE_ARR{10};
const int START_CUSTOMERS{3};
const int MAX_ROUNDS{10};

struct Node {
    string name;
    string order;
    Node* next;
};

void addRandomCustomer(Node*& front, Node*& back,
                       string names[], string drinks[]);

void addRandomMuffinCustomer(deque<Node>& muffinLine,
                             string names[], string muffins[]);

void addRandomBraceletCustomer(vector<Node>& braceletLine,
                               string names[], string bracelets[]);

void addRandomAvocadoCustomer(queue<Node>& avocadoLine,
                              string names[], string avocados[]);

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

    string bracelets[SIZE_ARR] {
        "Red Bracelet", "Blue Bracelet", "Green Bracelet", "Yellow Bracelet",
        "Purple Bracelet", "Pink Bracelet", "Black Bracelet", "White Bracelet",
        "Orange Bracelet", "Rainbow Bracelet"
    };

    string avocados[SIZE_ARR] {
        "Hass Avocado", "Organic Avocado", "Mini Avocado",
        "Large Avocado", "Ripe Avocado", "Green Avocado",
        "Avocado Toast Kit", "Guacamole Pack",
        "Avocado Salsa Cup", "Spicy Avocado Bowl"
    };

    Node* front{};
    Node* back{};

    deque<Node> muffinLine;
    vector<Node> braceletLine;
    queue<Node> avocadoLine;

    for (int i{0}; i < START_CUSTOMERS; ++i) {
        addRandomCustomer(front, back, names, drinks);
        addRandomMuffinCustomer(muffinLine, names, muffins);
        addRandomBraceletCustomer(braceletLine, names, bracelets);
        addRandomAvocadoCustomer(avocadoLine, names, avocados);
    }

    for (int numRound{1}; numRound <= MAX_ROUNDS; ++numRound) {
        cout << "---Round #" << numRound << "---\n";
        if (front != nullptr) {
            cout << "Coffee served: " << front->name << ": "
                               << front->order << '\n';
            Node* temp{front};
            front = front->next;
            delete temp;

            if (front == nullptr) {
                back = nullptr;
            }
        } else {
            cout << "No coffee customer served.\n";
        }

        if (rand() % 2 == 0) {
            addRandomCustomer(front, back, names, drinks);
            cout << "New coffee customer joined\n";
        } else {
            cout << "No new coffee customer joined\n";
        }

        if (!muffinLine.empty()) {
            cout << "Muffin served: " << muffinLine.front().name << ": "
                 << muffinLine.front().order << '\n';

            muffinLine.pop_front();
        } else {
            cout << "No muffin customer served\n";
        }

        if (rand() % 2 == 0) {
            addRandomMuffinCustomer(muffinLine, names, muffins);
            cout << "New muffin customer joined\n";
        } else {
            cout << "No new muffin customer joined\n";
        }

        if (!braceletLine.empty()) {
            cout << "Bracelet served: " << braceletLine.front().name << ": "
                 << braceletLine.front().order << '\n';
            braceletLine.erase(braceletLine.begin());
        } else {
            cout << "No bracelet customer served\n";
        }

        if (rand() % 2 == 0) {
            addRandomBraceletCustomer(braceletLine, names, bracelets);
            cout << "New bracelet customer joined\n";
        } else {
            cout << "No new bracelet customer joined\n";
        }

        if (!avocadoLine.empty()) {
            cout << "Avocado served: " << avocadoLine.front().name << ": "
                 << avocadoLine.front().order << '\n';
            avocadoLine.pop();
        } else {
            cout << "No avocado customer served\n";
        }

        if (rand() % 2 == 0) {
            addRandomAvocadoCustomer(avocadoLine, names, avocados);
            cout << "New avocado customer joined\n";
        } else {
            cout << "No new avocado customer joined\n";
        }

        cout << '\n';
    }

    Node* current{front};
    while (current != nullptr) {
        Node* temp{current};
        current = current->next;
        delete temp;
    }

    return 0;
}

void addRandomCustomer(Node*& front, Node*& back,
                       string names[], string drinks[]) {
    int rndNameIndex{rand() % SIZE_ARR};
    int rndDrinkIndex{rand() % SIZE_ARR};

    Node* customer{new Node};
    customer->name = names[rndNameIndex];
    customer->order = drinks[rndDrinkIndex];
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
    muffinCustomer.order = muffins[rand() % SIZE_ARR];
    muffinCustomer.next = nullptr;

    muffinLine.push_back(muffinCustomer);
}

void addRandomBraceletCustomer(vector<Node>& braceletLine,
                               string names[], string bracelets[]) {
    Node braceletCustomer;
    braceletCustomer.name = names[rand() % SIZE_ARR];
    braceletCustomer.order = bracelets[rand() % SIZE_ARR];
    braceletCustomer.next = nullptr;

    braceletLine.push_back(braceletCustomer);
}

void addRandomAvocadoCustomer(queue<Node>& avocadoLine,
                              string names[], string avocados[]) {
    Node avocadoCustomer;
    avocadoCustomer.name = names[rand() % SIZE_ARR];
    avocadoCustomer.order = avocados[rand() % SIZE_ARR];
    avocadoCustomer.next = nullptr;

    avocadoLine.push(avocadoCustomer);
}