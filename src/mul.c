#include "add.h"
#include "sub.h"

#include <stdint.h>

int mul(int a, int b) {
    int i;
    int32_t ap = a;
    int32_t bp = b;
    int val = 0;

    if (a < 0) {
        ap = sub(0, ap);
    }
    if (b < 0) {
        bp = sub(0, bp);
    }

    for (i = 0; i < bp; i = add(i, 1)) {
        val = add(val, ap);
    }

    if ((0x8000 & a) ^ (0x8000 & b)) {
        val = sub(0, val);
    }

    return val;
}
