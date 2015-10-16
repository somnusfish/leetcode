/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode* last;
    struct ListNode* new_head;
    struct ListNode* cur;
    
    int length = 0;
    int half_length = 0;
    int i=0;
    
    if((head==NULL) || (head->next==NULL)){
        return true;
    }

    new_head = head;
    while(new_head){
        new_head = new_head->next;
        length++;
    }
    
    half_length = length/2;
    new_head = head;
    for(i=0; i<half_length; i++){
        new_head = new_head->next;
    }
    
    if(length%2==1){
        cur = new_head;
        new_head = new_head->next;
    }
    
    last = new_head->next;
    new_head->next = NULL;
    while(last){
        cur = last;
        last = last->next;
        cur->next = new_head;
        new_head = cur;
    }
    
    for(i=0; i<half_length; i++){
        if((head->val)!=(new_head->val)){
            return false;
        }
        head = head->next;
        new_head = new_head->next;
    }
    
    return true;
}
