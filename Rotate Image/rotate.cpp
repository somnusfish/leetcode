class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size()-1;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix.size()-i; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-j][n-i];
                matrix[n-j][n-i] = temp;
            }
        }
        
        for(int i=0; i<= n/2; i++){
            for(int j=0; j<matrix.size(); j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-i][j];
                matrix[n-i][j] = temp;
            }
        }
    }
};
