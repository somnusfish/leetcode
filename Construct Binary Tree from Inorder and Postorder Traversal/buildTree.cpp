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
     TreeNode* buildSubTree(vector<int>& postorder, int pStart, int pEnd, vector<int> &inorder, int iStart, int iEnd){
        if(pStart > pEnd){
            return NULL;
        }
        
        int pPos;
        int iPos;
        int val = postorder[pEnd];
        TreeNode *root = new TreeNode(val);
        iPos = iStart;
        while(inorder[iPos]!=val){
            iPos++;
        }
        pPos = iPos-iStart + pStart-1;
        root->left = buildSubTree(postorder, pStart, pPos, inorder, iStart, iPos-1);
        root->right = buildSubTree(postorder, pPos+1, pEnd-1, inorder, iPos+1, iEnd);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size() ==0){
            return NULL;
        }
        return buildSubTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size() -1);
    }
};
