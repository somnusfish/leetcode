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
    void reorderList(ListNode* head) {
        if((head == NULL) || (head->next == NULL) || (head->next->next == NULL)){
            return;
        }
        int length=0;
        ListNode *p = head;
        
 
        while(p){
            length++;
            p = p->next;
        }
        int half = (length+1)/2;
        
        ListNode *reverseHead = head;
        ListNode *pre;
        for(int i=0; i<half; i++){
            pre = reverseHead;
            reverseHead = reverseHead->next;
        }
        pre->next = NULL;
        if(reverseHead->next != NULL){
            ListNode *q = reverseHead->next;
            ListNode *r = q->next;
            reverseHead->next = NULL;
            while(q){
                q->next = reverseHead;
                reverseHead = q;
                q = r;
                if(r){
                    r = r->next;
                }
            }
        }
        
        p = head;
        ListNode *q = reverseHead;
        ListNode *p_next = p->next;
        ListNode *q_next = q->next;
        while( p || q){
            p->next = q;
            if(q){
                q->next = p_next;
                q = q_next;
            }
            p = p_next;
            if(p){
                p_next = p_next->next;
            }
            if(q){
                q_next = q_next->next;
            }
        }
    
    }
};
