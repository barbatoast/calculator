#include "add.h"
#include "div.h"
#include "mul.h"
#include "sub.h"

#include <stdio.h>

int main(void) {
    int c;

    c = add(1, 2);
    printf("1 + 2 = %d\n", c);
    c = sub(1, 2);
    printf("1 - 2 = %d\n", c);
    c = mul(2, -3);
    printf("2 * -3 = %d\n", c);
    c = div(6, 2);
    printf("6 / 2 = %d\n", c);

    return 0;
}
