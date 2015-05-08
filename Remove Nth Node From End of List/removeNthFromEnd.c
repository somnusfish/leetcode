/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int length=0;
    int t;
    int i=1;
    struct ListNode *p = head;
    while(p){
        length++;
        p = p->next;
    }
    
    t = length-n;
    p = head;
    if(t==0){
        return head->next;
    }
    while(i<t){
        p = p->next;
        i++;
    }
    p->next = p->next->next;
    return head;
}
