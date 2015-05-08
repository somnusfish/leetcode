/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *pre;
    struct ListNode *cur;
    
    pre = NULL;
    cur = head;
    
    if(head==NULL){
        return head;
    }
    
    head = NULL;
    while(cur){
        if(cur->val!=val){
            if(pre==NULL){
                pre = cur;
                head = cur;
            }
            else{
                pre = cur;
            }
            cur = cur->next;
        }
        else{
            if(pre!=NULL){
                pre->next = cur->next;
            }
            cur = cur->next;
        }
    }
    return head;
}
