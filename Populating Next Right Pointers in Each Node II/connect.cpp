/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeLinkNode *> nextLevel(vector<TreeLinkNode *> &roots){
        vector<TreeLinkNode *> ret;
        for(int i=0; i<roots.size(); i++){
            if(i!=(roots.size()-1)){
                roots[i]->next = roots[i+1];
            }
            else{
                roots[i]->next = NULL;
            }
            if(roots[i]->left){
                ret.push_back(roots[i]->left);
            }
            if(roots[i]->right){
                ret.push_back(roots[i]->right);
            }
        }
        return ret;
    }
    void connect(TreeLinkNode *root) {
        vector<TreeLinkNode *> roots;
        if(root){
            roots.push_back(root);
            while(roots.size()!=0){
                roots = nextLevel(roots);
            }
        }
    }
};
