// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(1 == n){
            return 1;
        }
        int start = 1;
        int end = n;
        while(start <= end){
            int middle = start + (end-start)/2;
            if(isBadVersion(middle)){
                end = middle -1;
            }
            else{
                start = middle+1;
            }
        }
        return start;
    }
};
