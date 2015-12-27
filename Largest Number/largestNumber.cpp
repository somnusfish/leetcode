class Solution {
public:
    
    string largestNumber(vector<int>& nums) {
        string ret;
        vector<string> numsString;
        for(int i=0; i<nums.size(); i++){
            numsString.push_back(to_string(nums[i]));
        }
        sort(numsString.begin(), numsString.end(), [](string a, string b) {
            return (a+b) > (b+a);
        });
        
        for(int i=0; i<numsString.size(); i++){
            ret.append(numsString[i]);
        }
        if((ret.size()!=0) && ('0'==ret[0])){
            return "0";
        }
        else{
            return ret;
        }
    }
};
