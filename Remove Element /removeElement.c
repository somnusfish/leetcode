int removeElement(int A[], int n, int elem) {
    int i;
    int j;
    int temp;
    i = 0; 
    j = n-1;
    while(i<=j){
        if(A[i]==elem){
            temp = A[j];
            A[j] = A[i];
            A[i] = temp;
            j--;
        }
        else{
            i++;
        }
    }
    return j+1;
}
