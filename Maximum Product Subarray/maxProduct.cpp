class Solution {
public:
    int myMax(int a, int b, int c){
        if(a > b){
            if(a >c){
                return a;
            }
            else{
                return c;
            }
        }
        else{
            if(b > c){
                return b;
            }
            else{
                return c;
            }
        }
    }
    int myMin(int a, int b, int c){
        if(a < b){
            if(a < c){
                return a;
            }
            else{
                return c;
            }
        }
        else{
            if(b < c){
                return b;
            }
            else{
                return c;
            }
        }
    }
    int maxProduct(vector<int>& nums) {
        if(0 == nums.size()){
            return 0;
        }
        if(1 == nums.size()){
            return nums[0];
        }
        
        vector<int> max(nums.size(), 0);
        vector<int> min(nums.size(), 0);
        
        max[0] = nums[0];
        min[0] = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            if(0 == nums[i]){
                max[i] = 0;
                min[i] = 0;
            }
            else{
                max[i] = myMax(max[i-1]*nums[i], min[i-1]*nums[i], nums[i]);
                min[i] = myMin(max[i-1]*nums[i], min[i-1]*nums[i], nums[i]);
            }
        }
        
        int maxValue = max[0];
        for(int i=1; i<max.size(); i++){
            if(max[i] > maxValue){
                maxValue = max[i];
            }
        }
        return maxValue;
        
    }
};
