class Solution {
public:
    void combinationSumEach(vector<int> &candidates, int target, vector<int> &cur, vector<vector<int>> &total, int pos){
        if(candidates[0] > target){
            return;
        }
        if((pos == 0) && (candidates[0]!=target)){
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
                combinationSumEach(candidates, target-candidates[i], cur, total, i-1);
                cur.pop_back();
            }
            
            int temp = candidates[i];
            while(candidates[i] == temp){
                i--;
            }
            i++;
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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
