/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *left;
    int *right;
    int leftSize;
    int rightSize;
    int i;
    int j;
    int *ret;
    
    if(root==NULL){
        *returnSize = 0;
        return NULL;
    }
    left = preorderTraversal(root->left, &leftSize);
    right = preorderTraversal(root->right, &rightSize);
    
    ret = (int *)malloc(sizeof(int)*(1+leftSize+rightSize));
    ret[0] = root->val;
    for(i=0,j=1; i<leftSize; i++,j++){
        ret[j] = left[i];
    }
    for(i=0; i<rightSize; i++,j++){
        ret[j] = right[i];
    }
    
    free(left);
    free(right);
    *returnSize = leftSize+rightSize+1;
    return ret;
}
