class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != (s1.size() + s2.size())){
            return false;
        }
        if(s1.size() == 0){
            return !s2.compare(s3);
        }
        if(s2.size() == 0){
            return !s1.compare(s3);
        }
        bool **matchUp = new bool *[s1.size()+1];
        for(int i=0; i<=s1.size(); i++){
            matchUp[i] = new bool[s2.size()+1];
        }
        matchUp[0][0] = true;
        for(int i=1; i<=s1.size(); i++){
            matchUp[i][0] = (s1[i-1] == s3[i+0-1]) && matchUp[i-1][0];
        }
        for(int i=1; i<=s2.size(); i++){
            matchUp[0][i] = (s2[i-1] == s3[0+i-1]) && matchUp[0][i-1];
        }
        for(int i=1; i<=s1.size(); i++){
            for(int j=1; j<=s2.size(); j++){
                matchUp[i][j] = (matchUp[i-1][j] && (s1[i-1] == s3[i+j-1]))
                                || (matchUp[i][j-1] && (s2[j-1] == s3[i+j-1]));
            }
        }
        return matchUp[s1.size()][s2.size()];
    }
};
