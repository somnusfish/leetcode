class Solution {
public:
    void insert(vector<int>& line, int target){
        if(0 == line.size()){
            line.push_back(target);
            return;
        }
        if(target < line[0]){
            line.insert(line.begin()+0, target);
            return;
        }
        int i=0;
        while((i<line.size()) && (line[i] < target)){
            i++;
        }
        
        line.insert(line.begin()+i, target);
        return;
    }
    vector<int> bucketSort(vector<int>& nums){
        if(nums.size() <= 1){
            return nums;
        }
        vector<int> ret;
        int max = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > max){
                max = nums[i];
            }
        }
        vector< vector<int>> bucket(nums.size()+1);
        for(int i=0; i<nums.size(); i++){
            int bucketNum = nums[i]*nums.size()/max;
            insert(bucket[bucketNum], nums[i]);
        }
        for(int i=0; i<bucket.size(); i++){
            for(int j=0; j<bucket[i].size(); j++){
                ret.push_back(bucket[i][j]);
            }
        }
        return ret;
    }
    int maximumGap(vector<int>& nums) {
        if(nums.size() <=1 ){
            return 0;
        }
        vector<int> sortedNums = bucketSort(nums);
        int maxGap = 0;
        for(int i=1; i<sortedNums.size(); i++){
            if(sortedNums[i]-sortedNums[i-1] > maxGap){
                maxGap = sortedNums[i] - sortedNums[i-1];
            }
        }
        return maxGap;
    }
};
