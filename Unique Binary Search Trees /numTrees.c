int numTrees(int n) {
    int *f;
    int i;
    int j;
    f = (int *)malloc(sizeof(int)*(n+1));
    if(n<=0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    f[0] = 1;
    f[1] = 1;
    for(i=2; i<=n; i++){
        f[i] = 0;
        for(j=0; j<i; j++){
            f[i] += f[j]*f[i-1-j];
        }
    }
    return f[n];
}
