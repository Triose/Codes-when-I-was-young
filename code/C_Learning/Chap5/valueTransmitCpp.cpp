#include <stdio.h>

class S {
public:
    int age;
};

void changeAge(S s) {
    s.age++;
}

int main() {
    S s; s.age = 100;
    changeAge(s);
    printf("Age is: %i\n", s.age);
    return 0;
}
