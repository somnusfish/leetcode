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
    vector<TreeNode *> nextLevel(vector<TreeNode *> &roots, vector<vector<int>> &totalLevel, bool left){
        vector<TreeNode *> ret;
        vector<int> curLevel;
        for(int i=0; i<roots.size(); i++){
            if(left){
                curLevel.push_back(roots[i]->val);
            }
            else{
                curLevel.insert(curLevel.begin(), roots[i]->val);
            }
            if(roots[i]->left){
                ret.push_back(roots[i]->left);
            }
            if(roots[i]->right){
                ret.push_back(roots[i]->right);
            }
        }
        totalLevel.push_back(curLevel);
        return ret;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root){
            return ret;
        }
        vector<TreeNode *> roots;
        roots.push_back(root);
        bool tag = true;
        while(roots.size()!=0){
            roots = nextLevel(roots, ret, tag);
            tag  = !tag;
        }
        return ret;
    }
};
