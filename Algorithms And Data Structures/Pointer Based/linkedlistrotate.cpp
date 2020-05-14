/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    int x=0;
    if(A==NULL||A->next==NULL)return A;
    ListNode* root=A,*nroot=A,*front=A;
    while(root){
        ++x;
        root=root->next;
    }
    B%=x;
    if(!B)return A;
    int y=x-B,z=0;
    root=A;
    while(root->next!=NULL)root=root->next;
        root->next=front;
    root=front;
    z=0;
    while(z<=y){
       ++z;
       if(z==y){
           nroot=root->next;
           root->next=NULL;
           return nroot;
       }
       root=root->next;
    }
}
