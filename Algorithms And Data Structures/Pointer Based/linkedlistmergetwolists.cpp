/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *merge(ListNode* A, ListNode* B){
    if(!A)return B;
    if(!B)return A;
    if(A->val<=B->val){
        A->next=merge(A->next,B);
        return A;
    }
   B->next=merge(A,B->next);
   return B;
}

ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
  return merge(A,B);
}
