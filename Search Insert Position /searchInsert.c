int searchInsert(int* nums, int numsSize, int target) {
    int left;
    int right;
    int middle;
    left = 0;
    right = numsSize-1;
    middle = (left+right)/2;
    
    while(left<(right-1)){
        middle = (left+right)/2;
        if(nums[middle]==target){
            return middle;
        }
        else if(nums[middle]<target){
            left = middle; 
        }
        else{
            right = middle;
        }
    }
    
    if(target<=nums[left]){
        return left;
    }
    if(target>nums[right]){
        return right+1;
    }
    return left+1;
}
