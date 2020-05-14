/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *curr=A,*next,*temp,*temp2;
    if(A==NULL||A->next==NULL)return A;
    while(curr){
        next=curr->next;
        if(!next)return A;
        while(next&&curr->val==next->val){
            temp=next;
            temp2=next->next;
            free(temp);
            next=temp2;
        }
        curr->next=next;
        curr=curr->next;
    }
    return A;
}
