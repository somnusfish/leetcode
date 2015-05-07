int majorityElement(int num[], int n) {
    int candidate;
    int occurTimes;
    int i;
    
    candidate = num[0];
    occurTimes = 1;
    
    for(i=1; i<n; i++){
        if(num[i]!=candidate){
            occurTimes--;
            if(occurTimes == 0){
                candidate = num[i+1];
                i++;
                occurTimes = 1;
            }
        }
        else{
            occurTimes++;
        }
    }
    
    return candidate;
}
