class Solution {
public:
    int mySqrt(int x) {
        double last = 0.0;
        double cur = 1.0;
        
        if(x<=0){
            return 0;
        }
        
        while(abs(cur-last)>=1){
            last = cur;
            cur = (cur*cur+x)/(2*cur);
        }
        return (int)cur;
    }
};
