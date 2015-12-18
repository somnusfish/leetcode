class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur = 0;
        for(int i=0; i<nums.size(); i++){
            if(i<=cur){
                cur = max(cur, i+nums[i]);
                if(cur>=(nums.size()-1)){
                    return true;
                }
            }
            else{
                return false;
            }
        }
    }
};
