class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        vector<int> cur;
        if(nums.size()<=3){
            return ret;
        }
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size()-3; i++){
            cur.push_back(nums[i]);
            for(int j=i+1; j<nums.size()-2; j++){
                cur.push_back(nums[j]);
                int start = j+1;
                int end = nums.size()-1;
                while(start < end){
                    int sum = nums[i] + nums[j] + nums[start] + nums[end];
                    if(target == sum){
                        cur.push_back(nums[start]);
                        cur.push_back(nums[end]);
                        ret.push_back(cur);
                        cur.pop_back();
                        cur.pop_back();
                        int curStart = nums[start];
                        int curEnd = nums[end];
                        while(nums[start] == curStart){
                            start++;
                        }
                        while(nums[end] == curEnd){
                            end--;
                        }
                    }
                    else if(sum < target){
                        start++;
                    }
                    else{
                        end--;
                    }
                }
                
                cur.pop_back();
                while(nums[j+1] == nums[j]){
                    j++;
                }
            }
            
            cur.pop_back();
            while(nums[i+1] == nums[i]){
                i++;
            }
        }
        return ret;
    }
};
