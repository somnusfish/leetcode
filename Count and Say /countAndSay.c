char* countAndSay(int n) {
    if(n==1){
        return "1";
    }
    char *last = countAndSay(n-1);
    int i;
    int j;
    int length;
    int count;
    char *ret;
    
    length=0;
    while(last[length]){
        length++;
    }
    
    ret = (char *)malloc(sizeof(char)*(length*2+1));
    
    i=0;
    j=0;
    while(i<length){
        count = 1;
        while(last[i]==last[i+1]){
            i++;
            count++;
        }
        ret[j++] = count+'0';
        ret[j++] = last[i];
        i++;
    }
    ret[j] = '\0';
    return ret;
}
