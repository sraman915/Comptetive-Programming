/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int x=0;
    if(!A)return A;
    ListNode *root=A,*temp,*prev;
    while(root){
        ++x;
        root=root->next;
    }
    if(B>x)B=1;
    else B=x-B+1;
    if(B==1){
        temp=A;
        root=A->next;
        free(temp);
        return root;
    }
    root=A;
    prev=NULL;
    x=0;
    while(root){
        ++x;
        if(x==B){
            temp=root;
           prev->next=root->next;
           free(temp);
           return A;
        }
        prev=root;
        root=root->next;
    }

}
