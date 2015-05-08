void merge(int A[], int m, int B[], int n) {
    int ia = m-1;
    int ib = n-1;
    int i = m+n-1;
    
    while((ia>=0) && (ib>=0)){
        A[i--] = A[ia]>B[ib]? A[ia--]:B[ib--];
    }
    while(ia>=0){
        
        A[i--] = A[ia--];
    }
    while(ib>=0){
        A[i--] = B[ib--];
    }
}
