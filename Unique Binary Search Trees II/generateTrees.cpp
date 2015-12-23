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
    vector<TreeNode*> generate(int start, int end){
        vector<TreeNode *> subTree;
        if(start > end){
            subTree.push_back(NULL);
            return subTree;
        }
        for(int i=start; i<=end; i++){
            vector<TreeNode *> leftTree = generate(start, i-1);
            vector<TreeNode *> rightTree = generate(i+1, end);
            for(int j=0; j<leftTree.size(); j++){
                for(int k=0; k<rightTree.size(); k++){
                    TreeNode *root = new TreeNode(i);
                    root->left = leftTree[j];
                    root->right = rightTree[k];
                    subTree.push_back(root);
                }
            }
        }
        return subTree;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n<=0){
            vector<TreeNode *> root;
            return root;
        }
        return generate(1,n);
    }
};
