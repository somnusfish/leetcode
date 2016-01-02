class Solution {
public:
    void letterCombination(string digits, vector<string> &tables, int pos, string &cur, vector<string> &total){
        if(pos == digits.size()){
            total.push_back(cur);
            return;
        }
        int curNum = digits[pos] - '1';
        for(int i=0; i<tables[curNum].size(); i++){
            cur.push_back(tables[curNum][i]);
            letterCombination(digits, tables, pos+1, cur, total);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        string s;
        vector<string> tables(9);
        tables[1] = "abc";
        tables[2] = "def";
        tables[3] = "ghi";
        tables[4] = "jkl";
        tables[5] = "mno";
        tables[6] = "pqrs";
        tables[7] = "tuv";
        tables[8] = "wxyz";
        if(0 == digits.size()){
            return ret;
        }
        letterCombination(digits, tables, 0, s, ret);
        return ret;
    }
};
