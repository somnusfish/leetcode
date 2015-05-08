int lengthOfLastWord(char* s) {
    int start;
    int end;
    end = 0;
    if(!s){
        return 0;
    }
    while(isalpha(s[end])||(s[end]==' ')){
        end++;
    }
    end--;
    while(!isalpha(s[end])){
        end--;
    }
    start = end;
    while((s[start]!=' ')&&(start>=0)){
        start--;
    }
    return end-start;
    
}
