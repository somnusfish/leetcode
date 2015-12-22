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
    void findPath(TreeNode* root, int sum, vector<int> &onePath, vector<vector<int>> &allPath){
        if((root->left == NULL) && (root->right ==NULL)){
            if(root->val == sum){
                onePath.push_back(root->val);
                allPath.push_back(onePath);
                onePath.pop_back();
                return;
            }
            else{
                return;
            }
        }
        
        sum -= root->val;
        onePath.push_back(root->val);
        if(root->left){
            findPath(root->left, sum, onePath, allPath);
        }
        if(root->right){
            findPath(root->right, sum, onePath, allPath);
        }
        onePath.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> onePath;
        if(root==NULL){
            return ret;
        }
        else{
            findPath(root, sum, onePath, ret);
            return ret;
        }
    }
};
