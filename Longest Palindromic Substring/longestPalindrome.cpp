class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.length();
        int begin = 0;
        int max = 1;
        bool **common = new bool*[2];
        common[0] = new bool[length];
        common[1] = new bool[length];
        for(int i=0; i<length; i++){
            common[1][i] = true;
        }
        for(int i=0; i<length-1; i++){
            if(s[i]==s[i+1]){
                common[0][i] = true;
                begin = i;
                max = 2;
            }
            else{
                common[0][i] = false;
            }
        }
        for(int len = 3; len <= length; len++){
            for(int i=0; i<length-len+1; i++){
                int last = i+len-1;
                if((s[i]==s[last]) && (common[len%2][i+1]==true)){
                    common[len%2][i] = true;
                    begin = i;
                    max = len;
                }
                else{
                    common[len%2][i] = false;
                }
            }
        }
        
        
        return s.substr(begin,max);
    }
};
