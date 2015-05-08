int compareVersion(char* version1, char* version2) {
    int v1_val;
    int v2_val;
    int i=0;
    int j=0;
    
    while(version1[i] || version2[j]){
        v1_val = 0;
        v2_val = 0;
        v1_val = atoi(&version1[i]);
        v2_val = atoi(&version2[j]);
        
        if(v1_val<v2_val){
            return -1;
        }
        else if(v1_val>v2_val){
            return 1;
        }
        
        while(isdigit(version1[i])){
            i++;
        }
        if(version1[i]){
            i++;
        }
        while(isdigit(version2[j])){
            j++;
        }
        if(version2[j]){
            j++;
        }
        
    }
    return 0;
}
