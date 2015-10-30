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
    class CompareList {
        public:
        bool operator()(ListNode* t1, ListNode* t2) 
        {
        return (t1->val > t2->val);
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = NULL;
        ListNode *pre = head;
        ListNode *cur = NULL;
        int i=0;
    
        
        priority_queue<ListNode*, vector<ListNode*>, CompareList> myHeap;
        for(i=0; i<lists.size(); i++){
            if(lists[i]!=NULL){
                myHeap.push(lists[i]);
            }
        }
        
        while(!myHeap.empty()){
            cur = myHeap.top();
            myHeap.pop();
            if(head == NULL){
                head = cur;
                pre = head;
            }
            else{
                pre->next = cur;
                pre = cur;
            }
            
            cur = cur->next;
            if(cur != NULL){
                myHeap.push(cur);
            }
        }
        return head;
        
    }
};
