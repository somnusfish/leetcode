class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if(0 == nums.size()){
            return ret;
        }
        int start = 0;
        int end = 0;
        int i=0;
        for(i=0; i<nums.size(); i++){
            start  = i;
            while((i!=nums.size()-1) && (nums[i+1] == nums[i]+1)){
                i++;
            }
            end = i;
            string s;
            if(start == end){
                s = to_string(nums[start]);
            }
            else{
                s = to_string(nums[start]) +"->" + to_string(nums[end]);
            }
            ret.push_back(s);
        }
        return ret;
    }
};
