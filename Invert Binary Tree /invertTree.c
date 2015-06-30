/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode* left;
    struct TreeNode* right;
    
    if(root==NULL){
        return NULL;
    }
    
    left = root->left;
    right = root->right;
    
    root->left = invertTree(right);
    root->right = invertTree(left);
    
    return root;
    
}
