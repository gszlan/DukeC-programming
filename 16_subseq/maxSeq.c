#include "stddef.h"

size_t maxSeq(int * array, size_t n) {

    if (n < 2) return n;

    size_t maxSeq = 1;
    size_t currSeq = 1;

    for(int i = 1; i < n; i++) {
        if (array[i] > array[i-1]) currSeq++;
        else {
            if (currSeq > maxSeq) maxSeq = currSeq;
            currSeq = 1;
        }
    }

    return maxSeq > currSeq ? maxSeq : currSeq;
}
