
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        multimap<int, int> numsMap;
        multimap<int, int>::const_iterator c_it;
        for(int i=0; i<nums.size(); i++){
            numsMap.insert(make_pair(nums[i], i));
        }
        
        for(int i=0; i<nums.size(); i++){
            c_it = numsMap.find(nums[i]);
            numsMap.erase(c_it);
            int temp = target - nums[i];
            c_it = numsMap.find(temp);
            if(c_it!=numsMap.cend()){
                ret.push_back(i);
                ret.push_back((*c_it).second);
                
            }
        }
        
        return ret;
    }
};