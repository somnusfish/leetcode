/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes, int* returnSize) {
    int i;
    int j;
    int **ret;
    
    returnSize[0] = numRows;
    *columnSizes = (int *)malloc(sizeof(int*) * numRows);
    ret = (int **)malloc(sizeof(int*)*numRows);
    for(i=0; i<numRows; i++){
        columnSizes[0][i] = i+1;
        ret[i] = (int*)malloc(sizeof(int)*(i+1));
        ret[i][0] = 1;
        ret[i][i] = 1;
    }
    
    for(i=1; i<numRows; i++){
        for(j=1; j<i; j++){
            ret[i][j] = ret[i-1][j]+ret[i-1][j-1];
        }
    }
    return ret;
}
