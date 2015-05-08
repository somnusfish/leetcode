int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 0;
    int *res;
    int i;
    i = digitsSize-1;
   
    while(i>=0){
        carry = (digits[i]+1)/10;
        digits[i] = (digits[i]+1)%10;
        
        if(carry==0){
            returnSize[0] = digitsSize;
            return digits;
        }
        i--;
    }
    returnSize[0] = digitsSize+1;
    res = (int *)malloc(sizeof(int)*(digitsSize+1));
    res[0] = 1;
    for(i=0; i<digitsSize; i++){
        res[i+1] = digits[i];
    }
    return res;
}
