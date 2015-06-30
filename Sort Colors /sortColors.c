void sortColors(int* nums, int numsSize) {
    int red, white, blue;
    int i=0;
    
    red = 0;
    white = 0;
    blue = 0;
    
    for(i=0; i<numsSize; i++){
        switch(nums[i]){
            case 0:
                red++;
                break;
            case 1:
                white++;
                break;
            case 2:
                blue++;
                break;
            default:
                break;
        }
    }
    white += red;
    blue += white;
    
    for(i=0; i<red; i++){
        nums[i] = 0;
    }
    for(i=red; i<white; i++){
        nums[i] = 1;
    }
    for(i=white; i<blue; i++){
        nums[i] = 2;
    }
}
