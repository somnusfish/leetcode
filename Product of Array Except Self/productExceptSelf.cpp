class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(), 1);
        output[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            output[i] = nums[i] * output[i-1];
        }
        int reverseProduct = 1;
        for(int i=nums.size()-1; i>0; i--){
            output[i] = output[i-1]*reverseProduct;
            reverseProduct *= nums[i];
        }
        output[0] = reverseProduct;
        return output;
    }
};
