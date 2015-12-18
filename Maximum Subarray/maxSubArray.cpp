class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int *maxSum = new int[nums.size()];
        int max = nums[0];
        maxSum[0] = nums[0];
        for(int i=0; i<nums.size(); i++){
            if(maxSum[i-1]>0){
                maxSum[i] = nums[i] + maxSum[i-1];
            }
            else{
                maxSum[i] = nums[i];
            }
            max = max>maxSum[i] ? max : maxSum[i];
        }
        
        delete(maxSum);
        return max;
    }
};
