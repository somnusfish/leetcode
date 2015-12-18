class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2){
            return 0;
        }
        int maxTrapping = 0;
        int *maxL = new int[n];
        int *maxR = new int[n];
        
        maxL[0] = 0;
        maxR[n-1] = 0;
        for(int i=1; i<n; i++){
            if(height[i-1]>maxL[i-1]){
                maxL[i] = height[i-1];
            }
            else{
                maxL[i] = maxL[i-1];
            }
        }
        for(int i=n-2; i>=0; i--){
            if(height[i+1]>maxR[i+1]){
                maxR[i] = height[i+1];
            }
            else{
                maxR[i] = maxR[i+1];
            }
        }
        for(int i=0; i<n; i++){
            int curTrap = min(maxL[i],maxR[i])-height[i];
            if(curTrap>0){
                maxTrapping += curTrap;
            }
        }
        
        return maxTrapping;
    }
};
