int reverse(int x) {
    int tag;
    int _x = 0;
    int array[32];
    int end;
    int max = (1<<30)-1+(1<<30);
    tag = x>0? 1: -1;
    x = x>0? x: -x;
    
    while(x){
        
        if(_x>(max-x%10)/10){
            return 0;
        }
        _x = _x*10+x%10;
        x = x/10;
    }
    return _x*tag;
}
