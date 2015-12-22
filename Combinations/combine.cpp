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
            tag[i] = true;
            perLine.push_back(nums[i]);
            findCombine(nums,tag,perLine,totalCombine,k);
            tag[i] = false;
            perLine.pop_back();
            
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        vector<vector<int>> ret;
        vector<bool> tag(n,false);
        vector<int> perLine;
        if(k<=0){
            return ret;
        }
        for(int i=1; i<=n; i++){
            nums.push_back(i);
        }
        findCombine(nums, tag, perLine, ret, k);
        return ret;
    }
};
