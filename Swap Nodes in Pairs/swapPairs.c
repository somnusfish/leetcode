/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(!(head && head->next)){
        return head;
    }
    struct ListNode* p;
    struct ListNode* q;
    struct ListNode* prep;
    struct ListNode* qnext;
    
    p = head;
    q = head->next;
    qnext = q->next;
    
    head = q;
    q->next = p;
    p->next = qnext;
    
    while(qnext && (qnext->next)){
        prep = p;
        p = qnext;
        q = p->next;
        qnext = q->next;
        
        prep->next = q;
        q->next = p;
        p->next = qnext;
    }
    
    return head;
}
