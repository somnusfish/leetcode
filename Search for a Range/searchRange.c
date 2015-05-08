
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *ret;
    int start = 0;
    int end = numsSize-1;
    int middle;
    
    returnSize[0] = 2;
    ret = (int *)malloc(sizeof(int)*2);
    while(start < end){
        middle = (start+end)/2;
        
        if(nums[middle]<target){
            start = middle+1;
        }
        else if(nums[middle]>target){
            end = middle-1;
        }
        else{
            end = middle;
        }
    }
    if(nums[start] == target){
        ret[0] = start;
    }
    else{
        ret[0] = -1;
        ret[1] = -1;
        return ret;
    }
    
    end = numsSize-1;
    while(start<end){
        middle = (start+end)/2+1;
        
        if(nums[middle]>target){
            end = middle-1;
        }
        else{
            start = middle;
        }
    }
    
    ret[1] = start;
    return ret;
}
