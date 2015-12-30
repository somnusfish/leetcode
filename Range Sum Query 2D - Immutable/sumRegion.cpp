class NumMatrix {
public:
    vector<vector<int>> myMatrix;
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>> &matrix) {
        myMatrix = matrix;
        sum = matrix;
        if((myMatrix.size()>0) && (myMatrix[0].size() > 0)){
            for(int i=1; i<matrix.size(); i++){
                sum[i][0] += sum[i-1][0];
            }
            for(int i=1; i<matrix[0].size(); i++){
                sum[0][i] += sum[0][i-1];
            }
            for(int i=1; i<matrix.size(); i++){
                for(int j=1; j < matrix[i].size(); j++){
                    sum[i][j] += sum[i-1][j] + sum[i][j-1];
                    sum[i][j] -= sum[i-1][j-1];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if((myMatrix.size()>0) && (myMatrix[0].size() > 0)){
            if(0 == row1){
                if(0 == col1){
                    return sum[row2][col2];
                }
                else{
                    return sum[row2][col2] - sum[row2][col1-1];
                }
            }
            else{
                if(0 == col1){
                    return sum[row2][col2] - sum[row1-1][col2];
                }
                else{
                    return sum[row2][col2] - sum[row1-1][col2] - sum[row2][col1-1] + sum[row1-1][col1-1];
                }
            }
        }
        else{
            return 0;
        }
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
