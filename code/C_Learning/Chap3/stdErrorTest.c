#include <stdio.h>

int main() {
    int a,b;
    while(~scanf("%d %d", &a, &b)) {
	if(a > b) {
	    fprintf(stdout, "Stander output\n");
	} else {
	    fprintf(stderr, "Stander Error\n");
	    return 3;
	}
    }
    return 0;
}
