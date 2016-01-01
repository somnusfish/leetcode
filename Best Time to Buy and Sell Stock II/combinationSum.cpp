class Solution {
public:
    void combinationSumEach(vector<int>& candidates, int target, vector<int> &cur, vector<vector<int>> &total, int pos){
        if(target < candidates[0]){
            return;
        }
        for(int i=pos; i>=0; i--){
            if(candidates[i] == target){
                cur.push_back(candidates[i]);
                total.push_back(cur);
                cur.pop_back();
            }
            else if(candidates[i] < target){
                cur.push_back(candidates[i]);
                combinationSumEach(candidates, target-candidates[i], cur, total,i);
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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> cur;
        if(0 == candidates.size()){
            return ret;
        }
        sort(candidates.begin(), candidates.end());
        combinationSumEach(candidates, target, cur,  ret, candidates.size()-1);
        
        for(int i=0; i<ret.size(); i++){
            reverse(ret[i]);
        }
        return ret;
    }
};
