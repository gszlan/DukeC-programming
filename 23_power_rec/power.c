
unsigned power_helper(unsigned x, unsigned y, unsigned answer) {
    if ( y == 1) return answer;
    return power_helper(x, y - 1, answer * x);
}

unsigned power(unsigned x, unsigned y) {

    if ( y == 0) return 1;
    if ( y == 1) return x;
    unsigned answer = x * x;
    return power_helper(x, y - 1, answer);
}
