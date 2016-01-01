class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDiff = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            int start = i+1;
            int end = nums.size()-1;
            while(start<end){
                int diff = nums[i] + nums[start] + nums[end] - target;
                minDiff = abs(diff) < abs(minDiff)? diff : minDiff;
                if(0 == diff){
                    return target;
                }
                else if(diff>0){
                    end--;
                }
                else{
                    start++;
                }
            }
        }
        return target+minDiff;
    }
};
