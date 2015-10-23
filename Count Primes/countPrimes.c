int countPrimes(int n) {
    int count=0;
    int i;
    int j;
    int *tag;
    
    tag = (int *)malloc(sizeof(int)*(n));
    for(i=1; i<n; i++){
        tag[i] = 1;
    }
    
    count = 0;
    for(i=2; i<n; i++){
        if(tag[i]==1){
            count++;
            for(j=i; j<n; j+=i){
                tag[j] = 0;
            }
        }
    }
    
    return count;
}
