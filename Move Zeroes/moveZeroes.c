void moveZeroes(int* nums, int numsSize) {
    int first = -1;
    int i=0;
    
    for(i=0; i<numsSize; i++){
        if(nums[i]==0){
            if(first<0){
                first = i;
            }
            while((first<numsSize) && (nums[first]==0)){
                first++;
            }
            if(first==numsSize){
                return;
            }
            nums[i] = nums[first];
            nums[first] = 0;
        }
    }
    return;
    
}
