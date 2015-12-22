class Solution {
public:
    void findCombine(vector<int> &nums, vector<bool> &tag, vector<int> &perLine, vector<vector<int>> &totalCombine, int k){
        if(perLine.size() == k){
            totalCombine.push_back(perLine);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(tag[i]){
                continue;
            }
            if((perLine.size()!=0) && (nums[i]<perLine.back())){
                continue;
            }
            if((i>0) && (nums[i-1]==nums[i]) && (tag[i-1]==false)){
                continue;
            }
            tag[i] = true;
            perLine.push_back(nums[i]);
            findCombine(nums,tag,perLine,totalCombine,k);
            tag[i] = false;
            perLine.pop_back();
            
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> tag(nums.size(),false);
        vector<int> perLine;
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for(int i=0; i<=nums.size(); i++){
            findCombine(nums, tag, perLine, ret, i);
        }
        return ret;
    }
};
