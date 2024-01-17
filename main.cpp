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
protected:
    bool isDead = false;
private:
    int group;
    int health;
    string name;
public:
    Warrior(int a, bool s, int group, int health, const string &name) : Human(a, s), group(group), health(health),
                                                                        name(name) {}

    virtual ~Warrior() {

    }

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

    const string &getName() const {
        return name;
    }

    void Slogan() override {
        cout << "За Альяяянс! 😎🆒";
    }

    bool CheckHP() {
        if (health <= 0) {
            cout << "OH NO!! I'M DYINGGGG!!! HEELP SOMEBOOODY.......";
            isDead = true;
            return isDead;
        }
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

class Swordman : public Warrior {
private:
    string weapon = "sword";
public:
    Swordman(int a, bool s, int group, int health, const string &name) : Warrior(a, s, group, health, name) {}

    ~Swordman() override {

    }

    void Greeting() {
        string name = this->getName();
        int group = this->getGroup();
        cout << "Greetings! I'm a swordman called " << name << ". My group is " << group << ". Bye!\n";
        this->setHealth(0); // Хватает сил только на приветствие. Потом умирает (к сожалению). Никак не фиксится!
        CheckHP();
    }

};


int main() {
    setlocale(LC_ALL, "Russian");

    Human Artem(19, 1);
    Human Eugene(19, 1);
    Human Vika(19, 0);

    Swordman Papich(34, 1, 2, 5, "Arthas");
    Papich.Greeting();
    return 0;
}
