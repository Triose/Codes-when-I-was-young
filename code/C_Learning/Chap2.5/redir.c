#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    while(scanf("%99s", &str) == 1) 
	printf("%s\n", str);
    return 0;
}
