bool isPalindrome(char* s) {
    int start;
    int end;
    int temp;
    end = start = 0;
    while(s[end]){
        if(isalpha(s[end])){
            s[end] = tolower(s[end]);
        }
        temp = end;
        end ++;
    }
    end = temp;
    while(start<end){
        if(isalnum(s[start])){
            if(isalnum(s[end])){
                if(s[start]==s[end]){
                    start++;
                    end--;
                }
                else{
                    return false;
                }
            }
            else{
                end--;
            }
        }
        else{
            start++;
        }
    }
    return true;
}
