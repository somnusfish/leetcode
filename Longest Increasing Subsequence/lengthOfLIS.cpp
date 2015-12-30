class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums.size();
        }
        int *length = new int[nums.size()];
        for(int i=0; i<nums.size(); i++){
            length[i] = 1;
        }
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if((nums[j] < nums[i]) && (length[j]+1 > length[i])){
                    length[i] = length[j]+1;
                }
            }
        }
        int max = 1;
        for(int i=0; i<nums.size(); i++){
            if(length[i] > max){
                max = length[i];
            }
        }
        delete(length);
        return max;
    }
};
