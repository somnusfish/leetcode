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
    ListNode* rotateRight(ListNode* head, int k) {
        if((head==NULL)||(head->next==NULL)){
            return head;
        }
        ListNode* p = head;
        ListNode* tail = head;
        int length = 0;
        while(p){
            length++;
            tail = p;
            p = p->next;
        }
  
        k = k % length;
        if(k==0){
            return head;
        }
        
        
        int newhead = length-k+1;
        cout<< newhead <<endl;
        ListNode *newHead;
        ListNode *preHead;
        newHead = head;
        
         for(int i=1; i<newhead; i++){
            preHead = newHead;
            newHead = newHead->next;
        }
    
        tail->next = head;
        preHead->next = NULL;
        return newHead;
        
    }
};
