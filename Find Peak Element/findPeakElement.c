int findPeakElement(int* nums, int numsSize) {
    int L,R,M;
    int left,right,cur;
    L = 0; 
    R = numsSize-1;
    
    
    while(L<R){
        M = (L+R)/2;
        cur = nums[M];
        left = nums[M-1];
        right = nums[M+1];
        
        if((cur>left) && (cur>right)){
            return M;
        }
        else if(cur<right){
            L = M+1;
        }
        else{
            R = M-1;
        }
    }
    
    return L;
}
