
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> return_val;
        multimap<int, int> nums_map;
        multimap<int, int>::iterator it;
        for(int i=0; i<nums.size(); i++){
            nums_map.insert(make_pair(nums[i], i+1));
        }
        
        for(int i=0; i<nums.size(); i++){
            it = nums_map.find(nums[i]);
            nums_map.erase(it);
            int temp = target - nums[i];
            it = nums_map.find(temp);
            if(it!=nums_map.end()){
                return_val.push_back(i+1);
                return_val.push_back((*it).second);
                return return_val;
            }
        }
        
    }
};
