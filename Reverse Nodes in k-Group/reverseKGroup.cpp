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
    ListNode* reverseSection(ListNode *pre, ListNode *nextHead){
        //return the end of the reverse;
        ListNode* last = pre->next;
        ListNode* cur = last->next;
        while(cur!=nextHead){
            last->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = last->next;
        }
        return last;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if((NULL == head) || (k<=1)){
            return head;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *nextHead = head;
        int i = 0;
        while(nextHead){
            i++;
            nextHead = nextHead->next;
            if(0 == i%k){
                pre = reverseSection(pre, nextHead);
            }
            
        }
        return dummy->next;
     
    }
};
