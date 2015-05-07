/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *deleteDuplicates(struct ListNode *head) {
    struct ListNode *acEnd;
    struct ListNode *end;
    if(!head){
        return head;
    }
    acEnd = head;
    end = head->next;
    while(end){
        if(end->val!=acEnd->val){
            acEnd->next = end;
            end = end->next;
            acEnd = acEnd->next;
        }
        else{
            end = end->next;
        }
    }
    acEnd->next = end;
    return head;
}
