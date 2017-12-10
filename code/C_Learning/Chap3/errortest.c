#include <stdio.h>

int main() {
    char str[100];
    while(scanf("%99s", str) == 1) {
	if(*str == '0') return 2;
	printf("%s\n", str);
    }
    return 0;
}
