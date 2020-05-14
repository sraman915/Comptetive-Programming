/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *rev(ListNode *root){
ListNode *prev=NULL,*curr=root,*next=NULL;
while(curr){
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
}
return prev;
}

ListNode* Solution::reverseList(ListNode* A, int B) {
    if(!A||A->next==NULL||B<=1)return A;
    ListNode *start,*end,*prev=NULL,*temp,*root=NULL,*next,*root1=NULL;
    int x=1;
    start=A;
    while(root){
        while(x<B){
            ++x;
            root=root->next;
        }
        if(x==B){
            end=root;
            next=root->next;
            end->next=NULL;
            temp=rev(start);
            if(root1==NULL)
            root1=temp;
            if(prev)
            prev->next=temp;
            prev=start;
            start=next;
            root=next;
            x=1;
        }

    }
    return root1;
}
