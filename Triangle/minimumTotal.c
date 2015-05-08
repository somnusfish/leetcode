int minimumTotal(int **triangle, int numRows) {
    int i;
    int j;
    int *sum;
    int temp1;
    int temp2;
    
    sum = (int *)malloc(sizeof(int)*numRows);
    
    for(j=0; j<numRows; j++){
        sum[j] = triangle[numRows-1][j];
    }
    
    for(i=numRows-2; i>=0; i--){
        for(j=0; j<=i; j++){
            temp1 = triangle[i][j] + sum[j];
            temp2 = triangle[i][j] + sum[j+1];
            
            sum[j] = temp1<temp2?temp1:temp2;
        }
    }
    
    return sum[0];
}
