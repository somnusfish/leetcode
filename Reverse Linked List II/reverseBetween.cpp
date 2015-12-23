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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n){
            return head;
        }
        ListNode* preStart = NULL;
        ListNode* start = NULL;
        ListNode* end = NULL;
        ListNode* nextEnd = NULL;
        ListNode* reverseHead = NULL;
        ListNode* p = NULL;
        ListNode* cur = NULL;
        
        start = head;
        for(int i=1; i<m; i++){
            preStart = start;
            start = start->next;
        }
        end = start;
        for(int i=m; i<n; i++){
            end = end->next;
        }
        nextEnd = end->next;
        end->next = NULL;
        p = reverseHead = start;
        p = p->next;
        while(p){
            cur = p;
            p = p->next;
            cur->next = reverseHead;
            reverseHead = cur;
        }
        start->next = nextEnd;
        if(preStart){
            preStart->next = reverseHead;
            return head;
        }
        else{
            return reverseHead;
        }
        
    }
};
