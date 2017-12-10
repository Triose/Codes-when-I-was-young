#include <stdio.h>
#include <string.h>

struct fish {
    const char *name;
    const char *species;
    int teeth;
    int age;
};

void print(const struct fish ff) {
    printf("%s:\n", ff.name);
    printf("Species: %s\n", ff.species);
    printf("Teeth:%i\n", ff.teeth);
    printf("Age:%i\n", ff.age);
}

int main() {
    struct fish ff = {
	"Snappy",
	"Piranha",
	69,
	4
    };
    print(ff);
    return 0;
}
