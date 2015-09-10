/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
/*struct ListNode* reverse (struct ListNode *l){
    struct ListNode* ret;
    struct ListNode* p;
    if(!l){
        return l;
    }
    ret = l;
    l = l->next;
    ret->next = NULL;
    
    while(l){
        p = l;
        l = l->next;
        p->next = ret;
        ret = p;
    }
    
    return ret;
}*/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1;
    struct ListNode *p2;
    struct ListNode *ret;
    struct ListNode *head;
    struct ListNode *cur;
    int c = 0;
    
    p1 = l1;
    p2 = l2;
    
    if(!p1){
        return p2;
    }
    if(!p2){
        return p1;
    }
    
    ret = (struct ListNode *)malloc(sizeof(struct ListNode));
    ret->val = p1->val + p2->val;
    ret->next = NULL;
    cur = ret;
    p1 = p1->next;
    p2 = p2->next;
    if(ret->val >= 10){
        ret->val -= 10;
        c = 1;
    }
    
    while(p1 && p2){
        head = (struct ListNode *)malloc(sizeof(struct ListNode));
        head->next = NULL;
        cur->next = head;
        cur = head;
        head->val = c + p1->val + p2->val;
        if(head->val >=10){
            head->val -=10;
            c = 1;
        }
        else{
            c = 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    
    while(p1){
        head = (struct ListNode *)malloc(sizeof(struct ListNode));
        head->next = NULL;
        cur->next = head;
        cur = head;
        head->val = c + p1->val;
        if(head->val >=10){
            head->val -=10;
            c = 1;
        }
        else{
            c = 0;
        }
        p1 = p1->next;
    }
    
    while(p2){
        head = (struct ListNode *)malloc(sizeof(struct ListNode));
        head->next = NULL;
        cur->next = head;
        cur = head;
        head->val = c + p2->val;
        if(head->val >=10){
            head->val -=10;
            c = 1;
        }
        else{
            c = 0;
        }
        p2 = p2->next;
    }
    
    if(c==1){
        head = (struct ListNode *)malloc(sizeof(struct ListNode));
        head->next = NULL;
        cur->next = head;
        cur = head;
        head->val = 1;
    }
    return ret;
}
