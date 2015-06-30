int compar(const void *a, const void *b){
    int *aa = (int *)a;
    int *bb = (int *)b;
    if(*aa > *bb) return 1;
    if(*aa == *bb) return 0;
    if(*aa < *bb) return -1;
}
bool containsDuplicate(int* nums, int numsSize) {
    int i;
    int temp;
    
    if(numsSize<=1){
        return false;
    }
    
    qsort(nums, numsSize, sizeof(int), compar);
    temp = nums[0];
    for(i=1; i<numsSize; i++){
        if(nums[i]==nums[i-1]){
            return true;
        }
    }
    return false;
}
