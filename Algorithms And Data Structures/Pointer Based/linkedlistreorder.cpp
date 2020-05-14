/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    if(!A||A->next==NULL)return A;
    ListNode *p1=A->next,*p2=A,*curr,*prev=NULL,*next;
    while(p1&&p1->next){
        p1=p1->next->next;
        p2=p2->next;
    }
    curr=p2->next;
    p2->next=NULL;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    p1=A,p2=prev;
    curr=p1;
    p1=p1->next;
    while(p1||p2){
        if(p2){
            curr->next=p2;
            p2=p2->next;
            curr=curr->next;
        }
        if(p1){
            curr->next=p1;
            p1=p1->next;
            curr=curr->next;
        }
    }
    return A;
}
