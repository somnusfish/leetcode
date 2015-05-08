int strStr(char* haystack, char* needle) {
    char *temp;
    char *pointer = haystack;
    int i=0;
    if(!haystack[0]&&!needle[0]){
        return 0;
    }
    if(!haystack[0]){
        return -1;
    }
    temp = strstr(haystack, needle);
    
    if(!temp){
        return -1;
    }
    
    while(temp!=haystack){
        temp--;
        i++;
    }
    return i;
}
