int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int** f;
    int i,j;
    f = (int **)malloc(sizeof(int *)*gridRowSize);
    for(i=0; i<gridRowSize; i++){
        f[i] = (int *)malloc(sizeof(int)*gridColSize);
    }
    
    f[0][0] = grid[0][0];
    for(j=1; j<gridColSize; j++){
        f[0][j] = f[0][j-1]+grid[0][j];
    }
    
    for(i=1; i<gridRowSize; i++){
        f[i][0] = f[i-1][0] + grid[i][0];
    }
    
    for(i=1; i<gridRowSize; i++){
        for(j=1; j<gridColSize; j++){
            f[i][j] = f[i-1][j] < f[i][j-1] ? f[i-1][j]+grid[i][j] : f[i][j-1]+grid[i][j];
        }
    }
    
    return f[gridRowSize-1][gridColSize-1];
}
