int removeDuplicates(int A[], int n) {
    int tag=0;
    int start;
    int end;
    int i;
    if(n<=2){
        return n;
    }
    
    start = 0;
    end = 1;
    while(end<n){
        if(A[start]==A[end]){
            if(tag==0){
                tag = 1;
                A[++start] = A[end++];
            }
            else if(tag==1){
                end++;
            }
        }
        else{
            tag = 0;
            A[++start] = A[end++];
        }
    }
    return start+1;
}
