int singleNumber(int* nums, int numsSize) {
    int i;
    int ret;
    for(i=0; i<numsSize; i++){
        ret ^= nums[i];
    }
    return ret;
}
