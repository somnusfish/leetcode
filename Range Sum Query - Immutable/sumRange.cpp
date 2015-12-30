class NumArray {
public:
    vector<int> numArray;
    vector<int> sum;
    NumArray(vector<int> &nums) {
        for(int i=0; i<nums.size(); i++){
            numArray.push_back(nums[i]);
            if(0==i){
                sum.push_back(nums[i]);
            }
            else{
                sum.push_back(nums[i]+sum.back());
            }
        }
    }

    int sumRange(int i, int j) {
        if(0 == i){
            return sum[j];
        }
        else{
            return sum[j] - sum[i-1];
        }
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
