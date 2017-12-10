#include <stdio.h>

int main() {
    char str[] = "asdf";
    printf("%li\n", sizeof(str));
    str[5] = 'g';
    printf("%s\n", str);
    return 0;
}
