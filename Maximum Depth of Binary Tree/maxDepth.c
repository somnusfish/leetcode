/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
int maxDepth(struct TreeNode *root) {
    int leftDepth;
    int rightDepth;
    if(!root){
        return 0;
    }
    leftDepth = maxDepth(root->left) + 1;
    rightDepth = maxDepth(root->right) + 1;
    return leftDepth>rightDepth? leftDepth:rightDepth;
}
