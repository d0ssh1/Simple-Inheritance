#include <iostream>

class Human {
protected:
    int age;
    bool sex;
public:
    Human(int a, bool s) : age(a), sex(s) {}
};


int main() {
    Human Artem(19,1);
    Human Eugene(19,1);
    Human Vika(19,0);
    return 0;
}
