/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
int minDepth(struct TreeNode *root) {
    int leftDepth;
    int rightDepth;
    if(!root){
        return 0;
    }
    if(!(root->left||root->right)){
        return 1;
    }
    if(root->left && root->right){
        leftDepth = minDepth(root->left)+1;
        rightDepth = minDepth(root->right)+1;
        return leftDepth<rightDepth ? leftDepth : rightDepth;
    }
    else if(root->left){
        return minDepth(root->left)+1;
    }
    else{
        return minDepth(root->right)+1;
    }
}
