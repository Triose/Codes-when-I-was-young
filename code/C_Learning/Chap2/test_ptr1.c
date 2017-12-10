#include <stdio.h>

int main() {
    char str[5];
    fgets(str, sizeof(str), stdin);
    printf("%s\n", str);
    return 0;
}
