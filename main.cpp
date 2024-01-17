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
            cout << "OH NO!! I'M DYINGGGG!!! HEELP SOMEBOOODY.......\n";
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


class Archer : public Warrior {
private:
    string weapon = "bow";
public:
    Archer(int a, bool s, int group, int health, const string &name) : Warrior(a, s, group, health, name) {}

    ~Archer() override {

    }

    void Hit() {
        cout << "BOOM";
    }
};

class Wizard : public Warrior {
private:
    int magicalPoints = 100;
public:
    void MagicalSplash() {
        cout << "ElectroBOOM! *VZZZZ*";
        this->magicalPoints -= 10;
    }
};

class Squire : public Swordman, public Archer {
public:
    virtual void SecretPower() = 0;

    void SayStupid() {
        cout << "I can take your sword or bow!";
    }
};

class Powers { // Интерфейс
public:
    virtual ~Powers() {}

    virtual void magic() = 0;

    virtual void melee_strike() = 0;
};

class GodLikeBoy : public Powers, public Human {
private:
    string dist_weapon = "GodBOW";
    string melee_weapon = "GodSWORD";
public:
    GodLikeBoy(int a, bool s) : Human(a, s) {}

    ~GodLikeBoy() override {};

    void melee_strike() {
        cout << "Hey! I'll use " << melee_weapon << " right now! HEHE\n";
    }

    void magic() {
        cout << "OMG! I'll use " << dist_weapon << " right now! HOHO\n";
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Human Artem(19, 1);
    Human Eugene(19, 1);
    Human Vika(19, 0);

    Swordman Papich(34, 1, 2, 5, "Arthas");
    Papich.Greeting();

    GodLikeBoy Tema(19, 1);
    Tema.melee_strike();
    Tema.magic();

    return 0;
}
