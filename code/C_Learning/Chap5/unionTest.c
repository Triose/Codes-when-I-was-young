#include <stdio.h>

typedef union {
    int cnt;
    float weight;
    double volume;
}quantity;

int main() {
    quantity q = {.weight = 100.123 };
    q.cnt = 10;
    printf("%i\n", q.cnt);
    q.weight = 10.123;
    printf("%.3f\n", q.weight);
    q.volume = 123.123;
    printf("%.3lf\n", q.volume);
    printf("%i\n", q.cnt);
    return 0;
}
