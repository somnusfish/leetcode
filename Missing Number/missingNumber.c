int missingNumber(int* nums, int numsSize) {
    int value = 0;
    int max=0;
    int i;
    
    for(i=0; i<numsSize; i++){
        value ^= nums[i];
        value ^=i;
    }
    
    value ^= numsSize;

    return value;
}
