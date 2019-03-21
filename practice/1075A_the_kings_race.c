#include <stdio.h>

int main() {
    long long n, x, y;

    scanf("%lld", &n);
    scanf("%lld %lld", &x, &y);

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

    printf("%lld %lld\n", (MAX(x, y) - 1), (n - MIN(x, y)));
    printf("%lld %lld %lld\n", n, x, y);
    if ((MAX(x, y) - 1) > (n - MIN(x, y))) {
        printf("Black\n");
    }
    else {
        printf("White\n");
    }
    
    return 0;
}
