/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int *inorderTraversal(struct TreeNode *root, int *returnSize) {
    int leftSize;
    int rightSize;
    int *left;
    int *right;
    int *ret;
    int i;
    int j;
    int size;
    
    if(root==NULL){
        returnSize[0] = 0;
        return NULL;
    }
    
    left = inorderTraversal(root->left, &leftSize);
    right = inorderTraversal(root->right, &rightSize);
    
    size = leftSize+rightSize+1;
    returnSize[0] = size;
    
    ret = (int *)malloc(sizeof(int)*size);
    
    i=0;
    j=0;
    
    for(i=0; i<leftSize; i++){
        ret[j++] = left[i];
    }
    ret[j++] = root->val;
    for(i=0; i<rightSize; i++){
        ret[j++] = right[i];
    }
    return ret;
}
