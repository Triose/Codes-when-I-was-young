#include <stdio.h>

struct fish {
    const char *name;
    const char *species;
    int teeth;
    int age;
};

void print(const struct fish ff) {
    printf("Name: %s\n", ff.name);
    printf("Species: %s\n", ff.species);
    printf("Teeth: %i\n", ff.teeth);
    printf("Age: %i\n", ff.age);
}

int main() {
    struct fish snappy = {"Snappy", "Piranha", 69, 4};
    struct fish piranha = snappy;
    piranha.age = 100;
    print(piranha);
    print(snappy);
    return 0;
}
