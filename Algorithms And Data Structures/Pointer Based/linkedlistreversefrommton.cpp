/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


ListNode * rev(ListNode *root){
ListNode *newroot=NULL;
ListNode *prev=NULL,*curr=root,*next=NULL;
while(curr){
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
}
newroot=prev;
return newroot;
}

ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(!A||A->next==NULL)return A;
    if(B==C)return A;
    ListNode *root=A,*prev=NULL,*newroot,*curr,*next=NULL,*startm=NULL,*endm=NULL;
    int x=0;
    while(root){
        ++x;
        if(x+1==B)prev=root;
        if(x==B)startm=root;
        if(x==C)endm=root;
        if(x-1==C)next=root;
        root=root->next;
    }
    root=A;
    endm->next=NULL;
    curr=rev(startm);
    if(prev!=NULL)
    prev->next=curr;
    else root=curr;
    newroot=curr;
    while(newroot->next)
        newroot=newroot->next;
    newroot->next=next;
    return root;
}
