int trailingZeroes(int n) {
    int return_val = 0;
    while (n){
        return_val += n/5;
        n /= 5;
    }
    return return_val;
}
