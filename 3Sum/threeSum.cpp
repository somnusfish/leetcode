class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> cur;
        std::multiset<int> mymultiset;
        std::multiset<int>::iterator it;
        for(int i=0; i<nums.size(); i++){
            mymultiset.insert(nums[i]);
        }
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            it = mymultiset.find(nums[i]);
            if(it != mymultiset.end()){
                cur.push_back(nums[i]);
                mymultiset.erase(it);
                for(int j=i+1; j<nums.size(); j++){
                    while((j!=nums.size()-1) && (nums[j+1] == nums[j])){
                        j++;
                    }
                    int val = -nums[i]-nums[j]; 
                    if(((val > nums[j]) && (mymultiset.count(val)>0)) || ((val == nums[j]) && (mymultiset.count(val)>1))){
                        cur.push_back(nums[j]);
                        cur.push_back(val);
                        ret.push_back(cur);
                        cur.pop_back();
                        cur.pop_back();
                    }
                }
                cur.pop_back();
                mymultiset.erase(nums[i]);
            }
        }
        return ret;
    }
};
