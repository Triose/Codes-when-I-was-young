#include <stdio.h>
#include <string.h>

int main() {
    char s1[] = "dysfunctional";
    char s2[] = "fun";
    printf("%s\n", strstr(s1, s2));
    printf("%i\n", strstr(s1, s2) - s1);
    return 0;
}
