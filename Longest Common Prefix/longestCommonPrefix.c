char* longestCommonPrefix(char** strs, int strsSize) {
    int i=0;
    int j=0;
    int k=0;
    char *ret;
    if(!strs){
        return "";
    }
   
    if(!(strs[0])){
        return "";
    }
    for(j=0; j<strsSize; j++){
        if(!(strs[j])){
            return "";
        }
        if(!strs[j][0]){
            return "";
        }
    }
    while(strs[0][i]){
        for(j=0; j<strsSize; j++){
            if(!((strs[j][i])&&(strs[j][i]==strs[0][i]))){
                break;
            }
        }
        if(j!=strsSize){
            break;
        }
        else{
            i++;
        }
    }
    
    if(i==0){
        return "";
    }
    ret = (char *)malloc(sizeof(char)*i);
    for(k=0; k<i; k++){
        ret[k] = strs[0][k];
    }
    ret[k] = '\0';
    return ret;
}
