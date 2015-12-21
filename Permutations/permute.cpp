class Solution {
public:
    void findPermute(vector<int>& nums, vector<bool>& tag, vector<int> &perLine, vector<vector<int>>& allPermute){
        if(perLine.size() == nums.size()){
            allPermute.push_back(perLine);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(tag[i]){
                continue;
            }
            tag[i] = true;
            perLine.push_back(nums[i]);
            findPermute(nums, tag, perLine, allPermute);
            tag[i] = false;
            perLine.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<bool> tag(nums.size(), false);
        vector<int> perLine;
        if(nums.size()<=0){
            return ret;
        }
        findPermute(nums, tag, perLine, ret);
        
        return ret;
    }
};
