int climbStairs(int n) {
    int *A = (int *)malloc(sizeof(int)*(n+1));
    int i;
    if(n==0 || n==1){
        return 1;
    }
    A[0] = 1;
    A[1] = 1;
    for(i=2; i<=n; i++){
        A[i] = A[i-1]+A[i-2];
    }
    return A[n];
}
