int value(char s){
    if(s=='I'){
        return 1;
    }
    else if(s=='V'){
        return 5;
    }
    else if(s=='X'){
        return 10;
    }
    else if(s=='L'){
        return 50;
    }
    else if(s=='C'){
        return 100;
    }
    else if(s=='D'){
        return 500;
    }
    else if(s=='M'){
        return 1000;
    }
    else{
        return 0;
    }
}
int romanToInt(char* s) {
    int sum = 0;
    int i=0;
    int val1;
    int val2;
    while(s[i]){
        val1 = value(s[i]);
        if(value(s[i+1])){
            val2 = value(s[i+1]);
            if(val1<val2){
                sum -= val1;
            }
            else{
                sum += val1;
            }
            
        }
        else{
            sum += val1;
        }
        i++;
    }
    return sum;
}
