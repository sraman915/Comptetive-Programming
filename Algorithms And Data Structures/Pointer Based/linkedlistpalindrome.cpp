/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */



int Solution::lPalin(ListNode* A) {
 ListNode *curr=A,*mid=A,*prev,*newcurr,*newtemp,*newprev;
 if(A==NULL)return 1;
 if(A->next==NULL)return 1;
  while((curr!=NULL)&&(curr->next!=NULL)){
        curr=(curr->next)->next;
        prev=mid;
        mid=mid->next;
    }
    prev->next=NULL;
    newcurr=mid;
    while(newcurr!=NULL){
        newtemp=newcurr->next;
        if(newcurr==mid){
            newcurr->next=NULL;
            newprev=newcurr;
            newcurr=newtemp;
        }
        else{
            newcurr->next=newprev;
            newprev=newcurr;
            newcurr=newtemp;
        }
    }
    curr=A;
    while((newprev!=NULL)&&(curr!=NULL)){
        if(newprev->val!=curr->val){
            return 0;
        }
        newprev=newprev->next;
        curr=curr->next;
    }
    return 1;
}

