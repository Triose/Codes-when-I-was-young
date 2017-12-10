#include <stdio.h>

typedef struct {
    int age;
}S;

void changeAge(S s) {
    s.age++;
}


int main() {
    S s = {100};
    changeAge(s);
    printf("Age is: %i\n", s.age);
    return 0;
}
