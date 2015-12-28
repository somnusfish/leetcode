class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        int m = 0; 
        int n= 0;
        int countM = 0;
        int countN = 0;
        for(int i=0; i<nums.size(); i++){
            int a = nums[i];
            if((countM > 0) && (m == a)){
                countM++;
            }
            else if((countN > 0) && (n == a)){
                countN++;
            }
            else if(0 == countM){
                m = a;
                countM++;
            }
            else if(0 == countN){
                n = a;
                countN++;
            }
            else{
                countM--;
                countN--;
            }
        }
        int cM = 0;
        int cN = 0;
        for(int i=0; i<nums.size(); i++){
            if((countM > 0) && (m == nums[i])){
                cM++;
            }
            if((countN > 0) && (n == nums[i])){
                cN++;
            }
        }
        
        if((cM > 0) && (cM > (nums.size()/3))){
            ret.push_back(m);
        }
        if((cN > 0) && (cN > (nums.size()/3))){
            ret.push_back(n);
        }
        return ret;
    }
};
