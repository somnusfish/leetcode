/*
dynamic programming:
std::vector<int> sub: the length of longest substring without repeating characters which contain s[i].
int start: the start of current substring.
std::map <char, int> pos: last position of the character.

*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <=1){
            return s.size();
        }
        
        vector<int> sub(s.size(), 0);
        int start = 0;
        map<char, int> pos;
        
        for(int i=0; i<s.size(); i++){
            pos[s[i]] = -1;
        }
        sub[0] = 1;
        pos[s[0]] = 0;
        
        for(int i=1; i<s.size(); i++){
            if(pos[s[i]] < start){
                sub[i] = sub[i-1]+1;
            }
            else{
                start = pos[s[i]]+1;
                sub[i] = i-start+1;
            }
            pos[s[i]] = i;
        }
        
        int max = 0;
        for(int i=0; i<sub.size(); i++){
            max = max<sub[i] ? sub[i] :max;
        }
        return max;
        
    }
};
