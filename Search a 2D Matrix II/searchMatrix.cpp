class Solution {
public:
    int searchLine(vector<int> &line, int end, int target){
        int start = 0;
        while(start<end){
            int middle = (start+end)/2;
            if(target == line[middle]){
                return middle;
            }
            else if(target < line[middle]){
                end = middle-1;
            }
            else{
                start = middle+1;
            }
        }
        return start;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(0 == matrix.size()){
            return false;
        }
        if(0 == matrix[0].size()){
            return false;
        }
        int start = 0;
        int end = matrix[0].size()-1;
        for(int i=0; i<matrix.size(); i++){
            end = searchLine(matrix[i], end, target);
            if(end < matrix[i].size()){
                if(target == matrix[i][end]){
                    return true;
                }
            }
            else{
                end = matrix[i].size()-1;
            }
            
        }
    }
};
