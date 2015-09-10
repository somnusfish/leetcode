
int lengthOfLongestSubstring(char* s) {
    int tag[256] ;
    int i = 0;
    int length = 0;
    int *ret;
    int cur;
    int max=0;
    
    if(!s || !s[0]){
        return 0;
    }
    
    for(i=0; i<256; i++){
        tag[i] = -1;
    }
    i=0;
    while(s[i]){
        i++;
    }
    length = i;
    //ret[i] is the longest substring without repeating characters ending with s[i] 
    ret = (int *)malloc(sizeof(int) * length);
    
    ret[0] = 1;
    tag[s[0]] = 0;
    cur = 0;
    for(i=1; i<length; i++){
        if(tag[s[i]]<cur){
            ret[i] = ret[i-1]+1;
        }
        else{
            cur = tag[s[i]]+1;
            ret[i] = i-cur+1;
        }
        tag[s[i]] = i;
    }
    
    for(i=0; i<length; i++){
        if(ret[i]>max){
            max = ret[i];
        }
    }
    return max;
}i
