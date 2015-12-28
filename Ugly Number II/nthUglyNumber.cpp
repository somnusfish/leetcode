class Solution {
public:
    int nthUglyNumber(int n) {
        if(1 == n){
            return 1;
        }
        vector<int> ugly2(1,2);
        vector<int> ugly3(1,3);
        vector<int> ugly5(1,5);
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        int cur = 1;
        int min_ugly = 1;
        while(cur!=n){
            min_ugly = min(ugly2[p2], min(ugly3[p3], ugly5[p5]));
            cur++;
            if(min_ugly == ugly2[p2]){
                p2++;
            }
            if(min_ugly == ugly3[p3]){
                p3++;
            }
            if(min_ugly == ugly5[p5]){
                p5++;
            }
            ugly2.push_back(min_ugly*2);
            ugly3.push_back(min_ugly*3);
            ugly5.push_back(min_ugly*5);
        }
        return min_ugly;
    }
};
