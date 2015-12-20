/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newhead = NULL;
        ListNode* tail = NULL;
        ListNode* p = head;
        ListNode* pre = head;
        
        if((head==NULL) || (head->next==NULL)){
            return head;
        }
        while(p){
            pre = p;
            while((p->next != NULL) && (p->val == (p->next)->val)){
                p = p->next;
            }
            if(newhead == NULL){
                if(pre == p){
                    newhead = p;
                    tail = p;
                }
                
            }
            else{
                if(pre == p){
                    tail->next = p;
                    tail = p;
                }
            }
            
            p = p->next;
        }
        if(tail){
            tail->next = NULL;
        }
        return newhead;
        
    }
};
