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
    void findPath(TreeNode* root, vector<int> &onePath, vector<vector<int>> &totalPath){
        if(NULL == root){
            return;
        }
        onePath.push_back(root->val);
        if((NULL == root->left) && (NULL == root->right)){
            totalPath.push_back(onePath);
        }
        if(root->left){
            findPath(root->left, onePath, totalPath);
        }
        if(root->right){
            findPath(root->right, onePath, totalPath);
        }
        onePath.pop_back();
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        vector<int> onePath;
        vector<vector<int>> totalPath;
        findPath(root, onePath, totalPath);
        
        for(int i=0; i<totalPath.size(); i++){
            string s;
            for(int j=0; j<totalPath[i].size(); j++){
                if(j!=(totalPath[i].size()-1)){
                    s += to_string(totalPath[i][j]) + "->";
                }
                else{
                    s += to_string(totalPath[i][j]);
                }
            }
            ret.push_back(s);
        }
        return ret;
    }
};
