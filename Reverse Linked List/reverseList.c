/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *cur;
    struct ListNode *new_head;
    
    if(head==NULL){
        return head;
    }
    
    new_head = head;
    head = head->next;
    new_head->next = NULL;
    
    while(head){
        cur = head;
        head = head->next;
        cur->next = new_head;
        new_head = cur;
    }
    return new_head;
}
