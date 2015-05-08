uint32_t reverseBits(uint32_t n) {
    int i=0;
    int reversed_n = 0;
    while(n){
        if(n&1){
            reversed_n |= (1 << (31-i));
        }
        i++;
        n >>= 1;
    }
    return reversed_n;
}
