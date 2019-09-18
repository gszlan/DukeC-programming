#include <stdlib.h>
#include <stdio.h>

unsigned power (unsigned x, unsigned y);
void run_check(unsigned x, unsigned y, unsigned expected_ans, unsigned case_no);

int main() {

    run_check(1,1,1,1);
    run_check(0,0,1,2);
    run_check(1,2,1,3);
    run_check(2,2,4,4);
    run_check(0,1,0,5);
    run_check(1,0,1,6);
    run_check(2,0,1,7);
    run_check(2,3,8,8);
    run_check(2,21,2097152,11);
    run_check(36,6,2176782336,12);
    
    return EXIT_SUCCESS;
}



void run_check(unsigned x, unsigned y, unsigned expected_ans, unsigned case_no) {

    if (power(x,y) != expected_ans) {
        printf("Case: %u  x = %u, y = %u failed !\n",case_no,x,y);
        exit(EXIT_FAILURE);
    }
}

