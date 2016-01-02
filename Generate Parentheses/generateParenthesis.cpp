class Solution {
public:
    void generate(int n, int l, int r, string &s, vector<string> &all){
        if(r>l){
            return;
        }
        if((l == n) && (r == n)){
            all.push_back(s);
            return;
        }
        
        if(l<n){
            s.push_back('(');
            generate(n, l+1, r, s, all);
            s.pop_back();
        }
        if(r<n){
            s.push_back(')');
            generate(n,l,r+1,s,all);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> ret;
        if(0 == n){
            return ret;
        }
        generate(n, 0, 0, s, ret);
        return ret;
    }
};
