int uniquePaths(int m, int n) {
    int **array;
    int i,j;
    
    array = (int **)malloc(sizeof(int *)*(m));
    for(i=0; i<m; i++){
        array[i] = (int *)malloc(sizeof(int)*(n));
    }
    
    for(j=0; j<n; j++){
        array[0][j] = 1;
    }
    
    for(i=0; i<m; i++){
        array[i][0] = 1;
    }
    
    for(i=1; i<m; i++){
        for(j=1; j<n; j++){
            array[i][j] = array[i-1][j]+array[i][j-1];
        }
    }
    return array[m-1][n-1];
}
