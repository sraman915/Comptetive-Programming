/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
if(!A||A->next==NULL)return A;
ListNode *root=A,*prev=NULL,*nroot=A->next,*curr=A,*temp,*next=A->next;
while(curr&&next){
       temp=next->next;
        curr->next=temp;
        next->next=curr;
        if(prev!=NULL)
            prev->next=next;
        prev=curr;
        curr=curr->next;
        if(curr!=NULL)
            next=curr->next;
}
return nroot;
}

