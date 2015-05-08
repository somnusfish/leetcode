void setZeroes(int **matrix, int m, int n) {
    bool *rowm;
    bool *coln;
    int i;
    int j;
    
    rowm = (bool *)malloc(sizeof(bool)*m);
    coln = (bool *)malloc(sizeof(bool)*n);
    
    for(i=0; i<m; i++){
        rowm[i] = false;
    }
    for(i=0; i<n; i++){
        coln[i] = false;
    }
    
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            if(matrix[i][j]==0){
                rowm[i] = true;
                coln[j] = true;
            }
        }
    }
    
    for(i=0; i<m; i++){
        if(rowm[i]){
            for(j=0; j<n; j++){
                matrix[i][j] = 0;
            }
        }
    }
    
    for(j=0; j<n; j++){
        if(coln[j]){
            for(i=0; i<m; i++){
                matrix[i][j] = 0;
            }
        }
    }
}
