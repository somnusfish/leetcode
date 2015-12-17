class Solution {
public:
    string convert(string s, int numRows) {
        if((numRows==1)||(s.length()==1)){
            return s;
        }
        int row = numRows;
        int colum = s.length()/(2*row-2)+1;
        string t;
        
        for(int i=0; i<row; i++){
            for(int j=0; j<colum; j++){
                int reguPos = j*(2*row-2)+i;
                int zigPos = (j+1)*(2*row-2)-i;
                if((i==0)||(i==row-1)){
                    //without zigzag
                    if(reguPos<s.length()){
                        t.push_back(s[reguPos]);
                    }
                }
                else{
                    //with zigzag
                    if(reguPos<s.length()){
                        t.push_back(s[reguPos]);
                    }
                    if(zigPos<s.length()){
                        t.push_back(s[zigPos]);
                    }
                }
            }
        }
        return t;
    }
};
