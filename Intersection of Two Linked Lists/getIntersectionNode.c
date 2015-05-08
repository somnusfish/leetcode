/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lengthA,lengthB;
    int i;
    struct ListNode *A = headA;
    struct ListNode *B = headB;
    int delta;
    lengthA = 0;
    lengthB = 0;
    while(A){
        lengthA++;
        A = A->next;
    }
    while(B){
        lengthB++;
        B = B->next;
    }
    A = headA;
    B = headB;
    if(lengthB>lengthA){
        delta = lengthB-lengthA;
        while(delta){
            B = B->next;
            delta--;
        }
    }else if(lengthA>lengthB){
        delta = lengthA - lengthB;
        while(delta){
            A = A->next;
            delta--;
        }
    }
    
    while(A){
        if(A == B){
            return A;
        }
        A = A->next;
        B = B->next;
    }
    return A;
}
