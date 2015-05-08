/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
bool hasPathSum(struct TreeNode *root, int sum) {
    if(!root){
        return false;
    }
    if(!(root->left||root->right)){
        if (root->val==sum){
            return true;
        }
        else{
            return false;
        }
    }
    return hasPathSum(root->left, sum - root->val)||hasPathSum(root->right, sum - root->val);
}
