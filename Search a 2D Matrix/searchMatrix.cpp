class Solution {
public:
    int searchHead(vector<vector<int>>& matrix, int target){
        if(matrix.size()<=1){
            return 0;
        }
        if(matrix[0].size()==0){
            return 0;
        }
        int i = 0;
        int j = matrix.size()-1;
        while(i<=j){
            int m = (i+j)/2;
            int M = matrix[m][0];
            if (M==target){
                return m;
            }
            else if(M>target){
                j = m-1;
            }
            else{
                i = m+1;
            }
        }
        return j;
    }
    bool searchLine(vector<int>& line, int target){
        if(line.size()<=0){
            return false;
        }
        int i = 0;
        int j = line.size()-1;
        while(i<=j){
            int m = (i+j)/2;
            if(line[m] == target){
                return true;
            }
            else if(line[m] > target){
                j = m-1;
            }
            else{
                i = m+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lineNum = searchHead(matrix, target);
        if(lineNum < 0){
            return false;
        }
        return searchLine(matrix[lineNum], target);
    }
};
