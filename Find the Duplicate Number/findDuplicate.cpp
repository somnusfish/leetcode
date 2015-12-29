class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() <= 2){
            return nums[0];
        }
        int fast = 0;
        int slow = 0;
        fast = nums[nums[0]];
        slow = nums[0];
        while(fast != slow){
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        slow = 0;
        while(fast != slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};
