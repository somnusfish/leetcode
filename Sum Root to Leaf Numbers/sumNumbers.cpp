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
    int sumNumbers(TreeNode* root) {
        if(!root){
            return 0;
        }
        if((root->left == NULL) && (root->right == NULL)){
            return root->val;
        }
        int sum = 0;
        if(root->left){
            root->left->val += root->val*10;
            sum += sumNumbers(root->left);
        }
        if(root->right){
            root->right->val += root->val*10;
            sum += sumNumbers(root->right);
        }
        return sum;
    }
};
