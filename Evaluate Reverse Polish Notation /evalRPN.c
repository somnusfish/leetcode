bool _isdigit(char *tokens){
    if(isdigit(tokens[0])){
        return true;
    }
    else if(tokens[0]=='-' || tokens[0]=='+'){
        if(isdigit(tokens[1])){
            return true;
        }
    }
    return false;
}

int evalRPN(char** tokens, int tokensSize) {
    int *stack;
    int top=0;
    
    int temp;
    int num1;
    int num2;
    int curNum;
    int i;
    
    stack = (int *)malloc(sizeof(int)*tokensSize);
    for(i=0; i<tokensSize; i++){
        if(_isdigit(tokens[i])){
            temp = atoi(tokens[i]);
            stack[top++] = temp;
        }
        else{
            num2 = stack[--top];
            num1 = stack[--top];
            
            switch(tokens[i][0]){
                case '+':
                temp = num1+num2;
                break;
                case '-':
                temp = num1-num2;
                break;
                case '*':
                temp = num1 * num2;
                break;
                case '/':
                temp = num1 / num2;
                break;
                default:
                break;
            }
            
            stack[top++] = temp;
        }
    }
    return stack[--top];
    
}
