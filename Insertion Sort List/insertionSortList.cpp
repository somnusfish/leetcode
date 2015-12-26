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
    ListNode* insertionSortList(ListNode* head) {
        if((NULL == head) || (NULL == head->next)){
            return head;
        }
        ListNode *newHead = head;
        head = head->next;
        newHead->next= NULL;
        
        while(head){
            ListNode *cur = head;
            head = head->next;
            
            if(cur->val < newHead->val){
                cur->next = newHead;
                newHead = cur;
            }
            else{
                ListNode *p = newHead;
                while((p->next) && (p->next->val < cur->val)){
                    p = p->next;
                }
                ListNode *q = p->next;
                p->next = cur;
                cur->next = q;
            }
            
        }
        return newHead;
    }
};
