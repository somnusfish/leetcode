int cmp(const void *a, const void *b)
{
     return(*(char *)a-*(char *)b);
}
bool isAnagram(char* s, char* t) {
    int s_length = 0;
    int t_length = 0;
    int i=0;
    
    while(s[s_length]){
        s_length++;
    }
    
    while(t[t_length]){
        t_length++;
    }
    
    if(s_length!=t_length){
        return false;
    }
    
    qsort(s,s_length,sizeof(char),cmp);
    qsort(t,t_length,sizeof(char),cmp);
    for(i=0; i<s_length; i++){
        if(s[i]!=t[i]){
            return false;
        }
    }
    return true;
}
