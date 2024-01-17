#include <iostream>
#include "string"

using namespace std;

class Human {
protected:
    int age;
    bool sex;
public:
    Human(int a, bool s) : age(a), sex(s) {}

    int GetAge() const {
        return age;
    }

    void SetAge(int value) {
        age = value;
    }

    bool GetSex() const {
        return sex;
    }

    void SetSex(bool sexy) {
        sex = sexy;
    }

    virtual void Slogan() {
        cout << "За орду! 🤮";
    }
};

class Warrior : public Human {
private:
    int group;
    int health;
    string name;
public:
    Warrior(int a, bool s, int group, int health, const string &name) : Human(a, s), group(group), health(health),
                                                                        name(name) {}

    int getGroup() const {
        return group;
    }

    void setGroup(int group) {
        Warrior::group = group;
    }

    int getHealth() const {
        return health;
    }

    void setHealth(int health) {
        Warrior::health = health;
    }

    void Slogan() override {
        cout << "За Альяяянс! 😎🆒";
    }
};

class Leader : public Human {
private:
    string name;
public:
    void changeWarGroup(Warrior w, int g) {
        w.setGroup(g);
    }

    void Slogan() override {
        cout << "За Монолииит! 🫥";
    }
};

int main() {
    Human Artem(19, 1);
    Human Eugene(19, 1);
    Human Vika(19, 0);
    return 0;
}
