class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        int n = height.size();
        int left = 0; 
        int right = n-1;
        while(left<right){
            ret = max(ret, (right-left)*min(height[left],height[right]));
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return ret;
    }
};
