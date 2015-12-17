class Solution {
public:
    int longestValidParentheses(string s) {
        int ret = 0;
        int curLength = 0;
        stack<pair<int,char>> parenStack;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                parenStack.push(make_pair(i,s[i]));
            }
            else if(s[i]==')'){
                if((!parenStack.empty()) && (parenStack.top().second=='(')){
                    parenStack.pop();
                    
                    if(parenStack.empty()){
                        curLength = i+1;
                    }
                    else{
                        curLength = i-parenStack.top().first;
                    }
                    ret = curLength>ret?curLength:ret;
                }
                else{
                    parenStack.push(make_pair(i,s[i]));
                }
            }
        }
        return ret;
    }
};
