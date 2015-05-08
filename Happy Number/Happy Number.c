int happyValue(int n){
    int ret = 0;
    while(n){
        ret += (n%10)*(n%10);
        n = n/10;
    }
    return ret;
}
bool isHappy(int n) {
    int length = 4;
    int end=0;
    int start = 0;
    int happynum;
    int store[1000];
    
    happynum = happyValue(n);
    while(happynum!=1){
        for(start=0; start<end; start++){
            if(happynum==store[start]){
                return false;
            }
        }
        store[end++] = happynum;
        happynum = happyValue(happynum);
    }
    return true;
}
