/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    if(!A||A->next==NULL)return A;
    ListNode *root=A,*temp,*next,*prev=A,*nroot=NULL,*temp1,*curr=A->next;
    while(curr){
        next=curr->next;
        if(curr->val<prev->val){
            nroot=root;
            temp1=NULL;
            while(nroot!=curr){
                if(nroot->val>curr->val)
                break;
                temp1=nroot;
                nroot=nroot->next;
            }
            if(temp1==NULL){
                root=curr;
                curr->next=nroot;
                prev->next=next;
                curr=next;
            }
            else{
                temp1->next=curr;
                curr->next=nroot;
                prev->next=next;
                curr=next;
            }
        }
        else{
            prev=curr;
            curr=next;
        }
    }
  return root;
}
