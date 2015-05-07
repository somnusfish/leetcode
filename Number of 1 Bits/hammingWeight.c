int hammingWeight(uint32_t n) {
    int i=0;
    while(n){
        if(n&1){
            i++;
        }
        n >>= 1;
    }
    return i;
}
