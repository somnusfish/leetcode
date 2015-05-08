/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    struct TreeLinkNode *lp;
    struct TreeLinkNode *lc;
    struct TreeLinkNode *p;
    struct TreeLinkNode *c;
    if(!root){
        return ;
    }
    p = root;
    lp = root;
    c = p->left;
    lc = lp->left;
    
    root->next = NULL;
    while(lc){
        p = lp;
        c = lc;
        
        while(p){
            c->next = p->right;
            c = c->next;
            if(p->next){
                c->next = p->next->left;
                c = c->next;
            }
            p = p->next;
        }
        c->next = NULL;
        
        lp = lc;
        lc = lc->left;
    }
    
    
}
