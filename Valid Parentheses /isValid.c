bool push(char s){
    if((s=='(')||(s=='{')||(s=='[')){
        return true;
    }
    else{
        return false;
    }
}

char match(char s){
    if(s==')'){
        return '(';
    }
    if(s==']'){
        return '[';
    }
    if(s=='}'){
        return '{';
    }
}
bool isValid(char* s) {
    int i;
    int length=0;
    char *stack;
    int top;
    while(s[length]){
        length++;
    }
    stack = (char *)malloc(sizeof(char)*length);
    i = top = 0;
    while(i<length){
        if(push(s[i])){
            stack[top] = s[i];
            top++;
            i++;
        }
        else{
            if(stack[top-1]==match(s[i])){
                top--;
                i++;
            }
            else{
                return false;
            }
        }
    }
    if(top==0){
        return true;
    }
    else{
        return false;
    }
}
