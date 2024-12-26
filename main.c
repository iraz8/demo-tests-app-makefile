#include <stdio.h>
#include "sum.h"

int main(void) {
    int x, y;
    printf("Enter two integers: ");
    if (scanf("%d %d", &x, &y) != 2) {
        printf("Invalid input.\n");
        return 1;
    }
    printf("Sum of %d and %d is %d\n", x, y, add_numbers(x, y));
    return 0;
}
