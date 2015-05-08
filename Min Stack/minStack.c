typedef struct {
    int *ele;
    int *minEle;
    int top;
    int minTop;
    int max;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
    stack->ele = (int *)malloc(sizeof(int)*maxSize);
    stack->minEle = (int *)malloc(sizeof(int)*maxSize);
    stack->top = 0;
    stack->minTop = 0;
    stack->max = maxSize;
}

void minStackPush(MinStack *stack, int element) {
    if(stack->top>=stack->max){
        return;
    }
    stack->ele[stack->top++] = element;
    if(stack->top==1){
        stack->minEle[stack->minTop++] = element;
    }
    else if(element<=stack->minEle[stack->minTop-1]){
        stack->minEle[stack->minTop++] = element;
    }
}

void minStackPop(MinStack *stack) {
    int curEle;
    if(stack->top==0){
        return;
    }
    stack->top--;
    curEle = stack->ele[stack->top];
    if(curEle == stack->minEle[stack->minTop-1]){
        stack->minTop--;
    }
}

int minStackTop(MinStack *stack) {
    return stack->ele[stack->top-1];
}

int minStackGetMin(MinStack *stack) {
    return stack->minEle[stack->minTop-1];
}

void minStackDestroy(MinStack *stack) {
    free(stack->ele);
    free(stack->minEle);
}
