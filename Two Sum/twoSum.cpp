
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        map<int, int> numsMap;
        map<int, int>::const_iterator c_it;
        for(int i=0; i<nums.size(); i++){
            numsMap[nums[i]] = i;
        }
        
        for(int i=0; i<nums.size(); i++){
            c_it = numsMap.find(target-nums[i]);
            if((c_it!=numsMap.cend()) && (c_it->second!=i)){
                ret.push_back(i);
                ret.push_back(c_it->second);
                break;
            }
        }
        
        return ret;
    }
};