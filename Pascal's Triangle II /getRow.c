/**
 * Definition for an integer array.
 * struct IntArray {
 *     int* elements;
 *     int size;
 * };
 */
struct IntArray* getRow(int rowIndex) {
    int currow = 0;
    int i;
    struct IntArray *return_val = (struct IntArray*)malloc(sizeof(struct IntArray));
    return_val->size = rowIndex+1;
    return_val->elements = (int *)malloc(sizeof(int)*return_val->size);
    
    return_val->elements[0] = 1;
    for(currow=1; currow<=rowIndex; currow++){
        return_val->elements[currow] = 1;
        for(i=currow-1; i>0; i--){
            return_val->elements[i] = return_val->elements[i] + return_val->elements[i-1];
        }
    }
    return return_val;
}
