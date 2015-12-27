/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(NULL == root){
            return 0;
        }
        int leftHeight = 0;
        int rightHeight = 0;
        TreeNode *l = root;
        TreeNode *r = root;
        while(l){
            leftHeight ++;
            l = l->left;
        }
        while(r){
            rightHeight++;
            r = r->right;
        }
        if(leftHeight == rightHeight){
            return (1<<leftHeight) - 1;
        }
        else{
            return 1+countNodes(root->left) + countNodes(root->right);
        }
    }
};
