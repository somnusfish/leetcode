class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L,R,M;
        L = 0;
        R = nums.size()-1;
        while(L<=R){
            M = (L+R)/2;
            if(nums[M] == target){
                return M;
            }
            else if(nums[M] >= nums[L]){
                //increasing
                if((nums[L] <= target) && (target <= nums[M])){
                    R = M-1;
                }
                else{
                    L = M+1;
                }
            }
            else{
                if((nums[M] <= target) && (target <= nums[R])){
                    L = M+1;
                }
                else{
                    R = M-1;
                }
            }
            
        }
        return -1;
    }
};
