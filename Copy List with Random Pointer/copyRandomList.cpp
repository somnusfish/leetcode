/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode *, RandomListNode *> hashMap;
        RandomListNode *p=head;
        if(head == NULL){
            return head;
        }
        while(p){
            RandomListNode *temp = new RandomListNode(p->label);
            hashMap[p] = temp;
            p = p->next;
        }
        p = head;
        while(p){
            if(p->next){
                hashMap[p]->next = hashMap[p->next];
            }
            else{
                hashMap[p]->next = NULL;
            }
            if(p->random){
                hashMap[p]->random = hashMap[p->random];
            }
            else{
                hashMap[p]->random = NULL;
            }
            p = p->next;
        }
        return hashMap[head];
    }
};
