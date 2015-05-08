bool isPalindrome(int x) {
    int factor = 1;
    int min = -(1<<31);
    int max = (1<<30)-1+(1<<30);
    /*if(x == min){
        return false;
    }*/
    if(x<0){
        return false;
    }
    if(x<10){
        return true;
    }
    factor = 10;
    while((x/factor)>=10){
        factor *=10;
    }
    while(factor){
        if(factor == 1){
            return true;
        }
        if((x/factor) == (x%10)){
            x = x- x%10 - (x/factor)*factor;
            x = x/10;
            factor /= 100;
        }
        else{
            return false;
        }
    }
    return true;
}
