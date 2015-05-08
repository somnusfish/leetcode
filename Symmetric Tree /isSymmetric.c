/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
 
bool isMirror(struct TreeNode *tree1, struct TreeNode *tree2){
    if(!(tree1||tree2)){
        return true;
    }
    if(tree1&&tree2){
        if(tree1->val==tree2->val){
            return isMirror(tree1->left,tree2->right) && isMirror(tree1->right,tree2->left);
        }
        else{
            return false;
        }
    }
    return false;
}
bool isSymmetric(struct TreeNode *root) {
    if(!root){
        return true;
    }
    return isMirror(root->left, root->right);
}
