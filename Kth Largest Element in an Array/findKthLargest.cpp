class Solution {
public:
    int partition(vector<int>& nums, int start, int end){
        if(start > end){
            return -1;
        }
        if(start == end){
            return start;
        }
        int pivot = nums[end];
        int pos = start-1;
        for(int i=start; i<end; i++){
            if(nums[i] >= pivot){
                pos++;
                int temp = nums[pos];
                nums[pos] = nums[i];
                nums[i] = temp;
            }
        }
        nums[end] = nums[pos+1];
        nums[pos+1] = pivot;
        return pos+1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int pos = -1;
        int start = 0;
        int end = nums.size()-1;
        pos = partition(nums, start, end);
        while(pos!=(k-1)){
            if(pos > (k-1)){
                pos = partition(nums, start, pos-1);
            }
            else{
                pos = partition(nums, pos+1, end);
            }
        }
        return nums[pos];
    }
};
