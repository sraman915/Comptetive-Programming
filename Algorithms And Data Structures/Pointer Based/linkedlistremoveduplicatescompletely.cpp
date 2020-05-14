/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(!A)return A;
    if(!A->next)return A;
    ListNode *temp=NULL,*root=NULL,*prev=NULL;
    while(A){
        temp=A->next;
        if(!temp){
            if(prev==NULL){
                root=A;
                return root;
            }
            prev->next=A;
            return root;
        }
        if(A->val!=temp->val){
            if(prev==NULL){
                root=A;
                prev=A;
            }
            else {
                prev->next=A;
                prev=A;
            }
            A=A->next;
        }
        else{
        int t=temp->val;
        while(A&&A->val==t){
            temp=A->next;
            free(A);
            A=temp;
        }
        }
    }
    if(prev)
    prev->next=NULL;
    return root;
}
