class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet;
        for(int i=0; i<nums.size(); i++){
            hashSet.insert(nums[i]);
        }
        int longest = 0;
        for(int i=0; i<nums.size(); i++){
            int curLength = 0;
            curLength++;
            hashSet.erase(nums[i]);
            int val1 = nums[i]-1;
            int val2 = nums[i]+1;
            while(hashSet.count(val1)){
                hashSet.erase(val1);
                curLength++;
                val1--;
            }
            while(hashSet.count(val2)){
                hashSet.erase(val2);
                curLength++;
                val2++;
            }
            if(curLength > longest){
                longest = curLength;
            }
        }
        return longest;
    }
};
