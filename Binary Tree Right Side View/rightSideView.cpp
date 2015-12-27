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
    vector<TreeNode*> levelOrder(vector<TreeNode*> &roots, vector<int> &level){
        vector<TreeNode*> ret;
        for(int i=0; i<roots.size(); i++){
            level.push_back(roots[i]->val);
            if(roots[i]->left){
                ret.push_back(roots[i]->left);
            }
            if(roots[i]->right){
                ret.push_back(roots[i]->right);
            }
        }
        return ret;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> level;
        vector<int> ret;
        vector<TreeNode*> roots;
        if(NULL == root){
            return ret;
        }
        roots.push_back(root);
        while(roots.size()!=0){
            roots = levelOrder(roots, level);
            ret.push_back(level.back());
        }
        return ret;
    }
};
