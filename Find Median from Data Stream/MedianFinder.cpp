class MedianFinder {
public:
    vector<int> nums;
    
    int find(int num){
        int start = 0;
        int end = nums.size()-1;
        while(start <= end){
            int middle = start + (end-start)/2;
            if(nums[middle] == num){
                return middle;
            }
            else if(nums[middle] > num){
                end = middle-1;
            }
            else{
                start = middle+1;
            }
        }
        return start;
    }
    // Adds a number into the data structure.
    void addNum(int num) {
        int pos = find(num);
        if(pos < nums.size()){
            nums.insert(nums.begin()+pos, num);
        }
        else{
            nums.push_back(num);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        int middle = nums.size()/2;
        if(nums.size()%2){
            return nums[middle];
        }
        else{
            double temp = nums[middle] + nums[middle-1];
            temp /=2;
            return temp;
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
