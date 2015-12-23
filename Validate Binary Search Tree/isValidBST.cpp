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
    bool isValidBSTWithVal(TreeNode* root, bool minValid, int MIN, bool maxValid, int MAX){
        if(!root){
            return true;
        }
        if(minValid && (root->val <= MIN)){
            return false;
        }
        if(maxValid && (root->val >= MAX)){
            return false;
        }
        return isValidBSTWithVal(root->left, minValid, MIN, true, root->val) &&
                isValidBSTWithVal(root->right, true, root->val, maxValid, MAX);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBSTWithVal(root, false, INT_MIN, false, INT_MAX); 
    }
};
