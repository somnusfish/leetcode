bool isIsomorphic(char* s, char* t) {
    int length = 0;
    int i=0;
    char map_s_t[128] = {0};
    char map_t_s[128] = {0};
    //we already assume s t have the same length
    while(s[length]){
        length++;
    }
    
    for(i=0; i<length; i++){
        if(map_s_t[s[i]]==0){
            map_s_t[s[i]] = t[i];
        }
        else if(map_s_t[s[i]]!=t[i]){
            return false;
        }
    }
    
    for(i=0; i<length; i++){
        if(map_t_s[t[i]] == 0){
            map_t_s[t[i]] = s[i];
        }
        else if(map_t_s[t[i]]!=s[i]){
            return false;
        }
    }
    return true;
}
