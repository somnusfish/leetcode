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
    TreeNode* flattenTail(TreeNode* root){
        if((root->left == NULL) && (root->right == NULL)){
            return root;
        }
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        TreeNode *leftTail;
        TreeNode *rightTail;
        if(left){
            leftTail = flattenTail(left);
            root->right = left;
            root->left = NULL;
            if(right){
                rightTail = flattenTail(right);
                leftTail->right = right;
                return rightTail;
            }
            else{
                return leftTail;
            }
        }
        else{
            rightTail = flattenTail(right);
            return rightTail;
        }
        
    }
    void flatten(TreeNode* root) {
        if(root!=NULL){
            flattenTail(root);
        }
    }
};
