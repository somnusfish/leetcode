class Solution {
public:
    int jump(vector<int>& nums) {
        int ret = 0;
        int cur = 0;
        int last = 0;
        for(int i=0; i<nums.size(); i++){
            if(i>last){
                ret++;
                last = cur;
            }
            cur = max(i+nums[i], cur);
        }
        return ret;
    }
};
