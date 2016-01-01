class Solution {
public:
    void combinationSumEach(vector<int> &candidates, int target, int totalNum, int pos, vector<int> &cur, vector<vector<int>> &total){
        if(cur.size() == totalNum){
            return;
        }
        for(int i=pos; i>=0; i--){
            if(candidates[i] == target){
                cur.push_back(candidates[i]);
                if(cur.size() == totalNum){
                    total.push_back(cur);
                }
                cur.pop_back();
            }
            else if((i!=0) &&( candidates[i] < target)){
                cur.push_back(candidates[i]);
                combinationSumEach(candidates, target-candidates[i], totalNum, i-1, cur, total);
                cur.pop_back();
            }
        }
    }
    void reverse(vector<int> &cur){
        int start = 0;
        int end = cur.size()-1;
        int temp;
        while(start < end){
            temp = cur[start];
            cur[start] = cur[end];
            cur[end] = temp;
            start++;
            end--;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates;
        vector<int> cur;
        vector<vector<int>> ret;
        if(k>9){
            return ret;
        }
        for(int i=0; i<=9; i++){
            candidates.push_back(i);
        }
        combinationSumEach(candidates, n, k, 9, cur,  ret);
        
        for(int i=0; i<ret.size(); i++){
            reverse(ret[i]);
        }
        return ret;
    }
};
