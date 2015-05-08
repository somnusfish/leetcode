/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *head;
    struct ListNode *end;
    
    if(!l1){
        return l2;
    }
    else if(!l2){
        return l1;
    }
    
    if(l1->val < l2->val){
        head = end = l1;
        l1 = l1->next;
    }
    else{
        head = end = l2;
        l2 = l2->next;
    }
    
    while(l1&&l2){
        if(l1->val <l2->val){
            end->next = l1;
            l1 = l1->next;
            end = end->next;
        }
        else{
            end->next = l2;
            l2 = l2->next;
            end = end->next;
        }
    }
    
    if(l1){
        end->next = l1;
    }
    else{
        end->next = l2;
    }
    
    return head;
}
