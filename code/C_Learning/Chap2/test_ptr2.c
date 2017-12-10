#include <stdio.h>

int main() {
    char * str1 = "asdf";
    char * str2 = "asdf";
    printf("%s\n", (str1 == str2 ? "true" : "false"));
    return 0;
}
