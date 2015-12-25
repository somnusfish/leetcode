class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> val_index;
        for(int i=0; i<nums.size(); i++){
            if(val_index.find(nums[i]) == val_index.end()){
                val_index[nums[i]] = i;
            }
            else{
                if(i-val_index[nums[i]] <=k ){
                    return true;
                }
                else{
                    val_index[nums[i]] = i;
                }
            }
        }
        return false;
    }
};
