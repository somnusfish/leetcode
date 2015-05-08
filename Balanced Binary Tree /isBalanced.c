/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
int depth(struct TreeNode *root){
    int left;
    int right;
    if(!root){
        return 0;
    }
    left = depth(root->left);
    right = depth(root->right);
    return left>right?left+1:right+1;
}

bool isBalanced(struct TreeNode *root) {
    
    if(!root){
        return true;
    }
    if(abs(depth(root->left)-depth(root->right))<=1){
        return isBalanced(root->left) && isBalanced(root->right);
    }
    else{
        return false;
    }
}
