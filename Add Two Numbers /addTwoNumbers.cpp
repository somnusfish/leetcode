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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = new ListNode(0);
        ListNode *p2 = new ListNode(0);
        ListNode *header = new ListNode(0);
        ListNode *cur = header;
        p1->next = l1;
        p2->next = l2;
        int carry = 0;
        while((NULL != p1->next) && (NULL != p2->next)){
            p1 = p1->next;
            p2 = p2->next;
            int value = p1->val + p2->val + carry;
            carry = value>=10 ? 1 :0;
            value = value>=10 ? value-10 : value;
            ListNode *tmp = new ListNode(value);
            cur->next = tmp;
            cur = cur->next;
        }
        ListNode *p = (p1->next == NULL) ? p2 : p1;
        while(NULL != p->next){
            p = p->next;
            int value = p->val + carry;
            carry = value>=10 ? 1 :0;
            value = value>=10 ? value-10 : value;
            ListNode *tmp = new ListNode(value);
            cur->next = tmp;
            cur = cur->next;
        }
        
        if(carry == 1){
            cur->next = new ListNode(carry);
        }
        return header->next;
        
    }
};
