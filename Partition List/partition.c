/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* end;
    struct ListNode* cur;
    struct ListNode* start;
    cur = head;
    start = NULL;
    end = NULL;
    
    if((head==NULL) || (head->next == NULL)){
        return head;
    }
    
    if(head->val < x){
        start = head;
    }
    end = head;
    cur = end->next;
    
    while(cur){
        if(cur->val < x){
            if(start == NULL){
                end->next = cur->next;
                start = cur;
                start->next = head;
                head = start;
            }
            else{
                if(end!=start){
                    end->next = cur->next;
                    cur->next = start->next;
                    start->next = cur;
                    start = cur;
                }
                else{
                    end = end->next;
                    start = start->next;
                }
            }
            cur = end->next;
        }
        else{
            end = cur;
            cur = cur->next;
        }
    }
    return head;
}
