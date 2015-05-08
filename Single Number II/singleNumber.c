int singleNumber(int* nums, int numsSize) {
    int count[32]={0};
    int i=0;
    int j=0;
    int ret;
    
    for(i=0; i<numsSize; i++){
        for(j=0; j<32; j++){
            count[j] += (nums[i] & (1<<j)) ? 1:0;
        }
    }
    
    for(i=0; i<32; i++){
        count[i] = count[i]%3;
        ret += ((count[i]) << i);
    }
    
    return ret;
}
