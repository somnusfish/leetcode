class Solution {
public:
    void findPermute(vector<int> &nums, vector<bool> &tag, vector<int> &perLine, vector<vector<int>> &allPermute){
        if(perLine.size() == nums.size()){
            allPermute.push_back(perLine);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(tag[i]){
                continue;
            }
            else if((i>0) && (nums[i] == nums[i-1]) && (tag[i-1]==false)){
                continue;
            }
            else{
                tag[i] = true;
                perLine.push_back(nums[i]);
                findPermute(nums,tag,perLine,allPermute);
                tag[i] = false;
                perLine.pop_back();
            }
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> perLine;
        vector<bool> tag(nums.size(), false);
        if(nums.size() <=0 ){
            return ret;
        }
        sort(nums.begin(), nums.end());
        findPermute(nums, tag, perLine, ret);
        return ret;
    }
};
