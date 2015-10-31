class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0;
        int end = 0;
        int sum = 0;
        int length = 0;
        
        for(end=0; end<nums.size(); end++){
            sum = sum+nums[end];
            if(sum>=s){
                while((sum-nums[start])>=s){
                    sum -= nums[start];
                    start++;
                }
                if((length == 0) || (length > (end-start+1))){
                    length = end-start+1;
                }
                sum -= nums[start];
                start++;
            }
        }
        return length;
    }
};
