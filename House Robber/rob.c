int rob(int* nums, int numsSize) {
    int *value;
    int i;
    int temp;
    value = (int *)malloc(sizeof(int)*numsSize);
    
    if(numsSize<=0){
        return 0;
    }
    if(numsSize==1){
        return nums[0];
    }
    if(numsSize == 2){
        return nums[0]>nums[1]? nums[0] : nums[1];
    }
    
    value[0] = nums[0];
    value[1] = nums[1]>nums[0]? nums[1] : nums[0];
    
    for(i=2; i<numsSize; i++){
        temp = nums[i] + value[i-2];
        value[i] = temp>value[i-1]? temp: value[i-1];
    }
    return value[numsSize-1];
}
