class Solution {
public:
    int factorial(int n){
        int temp = 1;
        for(int i=1; i<=n; i++){
            temp *= i;
        }
        return temp;
    }
    void getkthPermutation(vector<int> &nums, string &ret, int k){
        if(k==1){
            for(int i=0; i<nums.size(); i++){
                ret.push_back(nums[i]+'0');
            }
            return;
        }
        int total = factorial(nums.size()-1);
        int pos = (k-1)/total;
        int remain = (k-1)%total+1;
        ret.push_back(nums[pos]+'0');
        nums.erase(nums.begin()+pos);
        getkthPermutation(nums, ret, remain);
        
    }
    string getPermutation(int n, int k) {
        vector<int> nums;
        string ret;
        for(int i=1; i<=n; i++){
            nums.push_back(i);
        }
        getkthPermutation(nums,ret,k);
        return ret;
    }
};
