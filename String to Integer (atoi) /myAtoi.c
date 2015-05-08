int myAtoi(char* str) {
    int num = 0;
    int i = 0;
    int tag = 1;
    int max = (1<<30) -1 + (1<<30);
    while(str[i]==' '){
        i++;
    }
    
    if(str[i]=='-'){
        tag = -1;
        i++;
    }
    else if(str[i]=='+'){
        tag = 1;
        i++;
    }
    while(isdigit(str[i])){
        if((num > max/10) || ((num == max/10) && ((str[i]-'0')>max%10))){
            if(tag ==1){
                return max;
            }
            else{
                return 1<<31;
            }
        }
        else{
            num = num*10 + str[i] - '0';
            i++;
        }
    }
    return num*tag;
}
