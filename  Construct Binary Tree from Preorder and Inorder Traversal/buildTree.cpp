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
    TreeNode* buildSubTree(vector<int>& preorder, int pStart, int pEnd, vector<int> &inorder, int iStart, int iEnd){
        if(pStart > pEnd){
            return NULL;
        }
        
        int pPos;
        int iPos;
        TreeNode *root = new TreeNode(preorder[pStart]);
        iPos = iStart;
        while(inorder[iPos]!=preorder[pStart]){
            iPos++;
        }
        pPos = iPos-iStart + pStart;
        root->left = buildSubTree(preorder, pStart+1, pPos, inorder, iStart, iPos-1);
        root->right = buildSubTree(preorder, pPos+1, pEnd, inorder, iPos+1, iEnd);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() ==0){
            return NULL;
        }
        return buildSubTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size() -1);
    }
};
