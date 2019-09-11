#include "stddef.h"
#include "stdio.h"
#include "stdlib.h"

 size_t maxSeq(int * array, size_t n);

void doTesting(int * array, size_t n, size_t result, int testCase) {
     if (maxSeq(array, n) != result) {
         printf("Failed on test: %d\n", testCase);
         exit(EXIT_FAILURE);
     } else {
         printf("PAssed test: %d\n", testCase);
     }

 }
 
 int main() {
    
    int arr1[] = {1,1,1,3,5,6,4,3,-4,-2,1,2,6,7,8,9};
    int arr2[] = {};
    int arr3[] = {1};
    int arr4[] = {1,2,4};
    int arr5[] = {1,3,3,4};
    int arr6[] = {4,3,1};
    int arr7[] = {-3,-2,-1};

    doTesting(arr1,16,8,1);
    doTesting(arr2,0,0,2); 
    doTesting(arr3,1,1,3); 
    doTesting(arr4,3,3,4); 
    doTesting(arr5,4,2,5); 
    doTesting(arr6,3,1,6);
    doTesting(arr7,3,3,7);

    return EXIT_SUCCESS;
 }
