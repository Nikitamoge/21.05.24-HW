#include <iostream>
using namespace std;

class Boss {
private:
    static Boss* instance;
    int health;

    Boss(int h) : health(h) {}

public:
    static Boss* getSingleTone() {
        if (instance == nullptr) {
            instance = new Boss(100);
            cout << "Boss has been created with " << instance->getHealth() << " health." << endl;
        }
        return instance;
    }

    static void destroySingleTone() {
        if (instance != nullptr) {
            cout << "Boss is defeated!" << endl;
            delete instance;
            instance = nullptr;
        }
    }

    int getHealth() const {
        return health;
    }

    void setHealth(int h) {
        health = h;
        cout << "Boss health after hit: " << getHealth() << endl;
        if (health <= 0) {
            destroySingleTone();
        }
    }

    void takeDamage(int damage) {
        setHealth(getHealth() - damage);
    }
};

Boss* Boss::instance = nullptr;

int main() {
    Boss* boss = Boss::getSingleTone();
    cout << "Initial Boss health: " << boss->getHealth() << endl;

    while (boss->getHealth() > 0) {
        int damage;
        cout << "Enter damage to deal to the Boss: ";
        cin >> damage;
        boss->takeDamage(damage);
    }

    return 0;
}
