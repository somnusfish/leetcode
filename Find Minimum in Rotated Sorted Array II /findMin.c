
int findMin(int* nums, int numsSize) {
    int L,R,M;
    L=0; 
    R=numsSize-1;
    while((L<R) && (nums[R]<=nums[L])){
        M = (L+R)/2;
        if(nums[M]>nums[L]){
            L = M+1;
        }
        else if(nums[M]<nums[R]){
            R = M;
        }
        else{
            L = L+1;
        }
    }
    return nums[L];
}
