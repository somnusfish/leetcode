double myPow(double x, int n) {
    int i;
    double ret = 1.0;
    
    if(n<0){
        if(n<<1){
            return 1.0/myPow(x, -n);
        }
        else{
            return (1.0/myPow(x, -(n+1)))/x;
        }
    }
    
    while(n>0){
        if(n&1){
            ret *= x;
        }
        x *= x;
        n >>= 1;
    }
    return ret;
}
