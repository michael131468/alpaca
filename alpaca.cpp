#include "alpaca.h"

#include <cstdlib>

int* magic_counter() {
    int* ptr = (int*) malloc(sizeof(int));
    *ptr = 3;
    return ptr;
}

int* count_alpacas() {
    return magic_counter();
}
