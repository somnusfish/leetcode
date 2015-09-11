/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode* pre;
    struct ListNode* cur;
    
    pre = node;
    cur = pre->next;
    
    while(cur->next){
        pre->val = cur->val;
        pre = pre->next;
        cur = cur->next;
    }
    pre->val = cur->val;
    pre->next = NULL;
    free(cur);
}
