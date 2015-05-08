int gcd(int a, int b){
    if(a<b){
        gcd(b,a);
    }
    if(a%b){
        gcd(b,a%b);
    }
    else{
        return b;
    }
}
void rotate(int nums[], int n, int k) {
    int lcm;
    int i,j,p;
    int incount,outcount;
    int temp;
    int gcd_nk;
    
    if(k>n){
        k = k%n;
    }
    if(k==0){
        return;
    }
    gcd_nk = gcd(n,k);
    lcm = gcd_nk * (n/gcd_nk) * (k/gcd_nk);
    incount = lcm/k;
    outcount = n/incount;
    for (j=0; j<outcount; j++){
        for(p=0,i=j; p<incount-1; p++,i+=k){
            temp = nums[(i+k)%n];
            nums[(i+k)%n] = nums[j];
            nums[j] = temp;
        }
    }
    /*int *temp = (int *)malloc(sizeof(int)*n);
    int i;
    for(i=0; i<n; i++){
        temp[(i+k)%n] = nums[i];
    }
    for(i=0; i<n; i++){
        nums[i] = temp[i];
    }*/
}
