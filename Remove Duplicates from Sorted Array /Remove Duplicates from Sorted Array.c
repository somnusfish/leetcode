int removeDuplicates(int A[], int n) {
    int start;
    int end;
    int temp;
    start = 0;
    end = 1;
    
    if(n<=1){
        return n;
    }
    while(end<n){
        if(A[start]==A[end]){
            end++;
        }
        else{
            A[++start] = A[end++];
        }
    }
    return start+1;
}
