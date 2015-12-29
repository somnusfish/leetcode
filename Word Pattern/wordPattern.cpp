class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> stringCut;
        string temp = str;
        std::size_t pos = temp.find(' ');
        while(pos != std::string::npos){
            stringCut.push_back(temp.substr(0, pos));
            temp = temp.substr(pos+1);
            pos = temp.find(' ');
        }
        stringCut.push_back(temp);
        
        if(stringCut.size() != pattern.size()){
            return false;
        }
        
        map<string, char> tableR;
        map<char, string> tableS;
        
        for(int i=0; i<stringCut.size(); i++){
            if(tableR.count(stringCut[i]) == 0){
                tableR[stringCut[i]] = pattern[i];
            }
            else{
                if(tableR[stringCut[i]] != pattern[i]){
                    return false;
                }
            }
        }
        for(int i=0; i<stringCut.size(); i++){
            if(tableS.count(pattern[i]) == 0){
                tableS[pattern[i]] = stringCut[i];
            }
            else{
                if(tableS[pattern[i]].compare(stringCut[i])){
                    return false;
                }
            }
        }
        return true;
    }
};
