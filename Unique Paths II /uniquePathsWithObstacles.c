int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int **ret;
    int i;
    int j;
    ret = (int **)malloc(sizeof(int *)*obstacleGridRowSize);
    for(i=0; i<obstacleGridRowSize; i++){
        ret[i] = (int *)malloc(sizeof(int)*obstacleGridColSize);
    }
    
    if(obstacleGrid[0][0]==0){
        ret[0][0] = 1;
    }
    else{
        ret[0][0] = 0;
    }
    for(j=1; j<obstacleGridColSize; j++){
        if(obstacleGrid[0][j]==0){
            ret[0][j] = ret[0][j-1];
        }
        else{
            ret[0][j] = 0;
        }
    }
    
    for(i=1; i<obstacleGridRowSize; i++){
        if(obstacleGrid[i][0]==0){
            ret[i][0] = ret[i-1][0];
        }
        else{
            ret[i][0] = 0;
        }
    }
    
    for(i=1; i<obstacleGridRowSize; i++){
        for(j=1; j<obstacleGridColSize; j++){
            if(obstacleGrid[i][j]==0){
                ret[i][j] = ret[i-1][j] + ret[i][j-1];
            }
            else{
                ret[i][j] = 0;
            }
        }
    }
    
    return ret[obstacleGridRowSize-1][obstacleGridColSize-1];
}
