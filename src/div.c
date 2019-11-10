#include "add.h"
#include "sub.h"

#include <stdint.h>

int div(int a, int b) {
    int32_t ap = a;
    int32_t bp = b;
    int val = 0;

    if (a < 0) {
        ap = sub(0, ap);
    }
    if (b < 0) {
        bp = sub(0, bp);
    }

    while (ap > 0) {
        ap = sub(ap, bp);
        if (ap < 0) {
            break;
        }
        val = add(val, 1);
    }

    if ((0x8000 & a) ^ (0x8000 & b)) {
        val = sub(0, val);
    }

    return val;
}
