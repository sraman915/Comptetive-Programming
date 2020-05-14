/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 ListNode *merge(ListNode *A,ListNode *B){
     if(A==NULL)return B;
     if(B==NULL)return A;
    ListNode *root1=A,*root2=B,*root=NULL,*end=NULL,*temp;
    while(root1&&root2){
        if(root1->val<root2->val){
            temp=root1;
            root1=root1->next;
        }
        else{
            temp=root2;
            root2=root2->next;
        }
        if(!root){
            root=temp;
            end=temp;
        }
        else {
            end->next=temp;
            end=end->next;
        }
    }
    while(root1){
        end->next=root1;
        end=root1;
        root1=root1->next;
    }
    while(root2){
        end->next=root2;
        end=root2;
        root2=root2->next;
    }
    if(end)end->next=NULL;
    return root;
 }

ListNode *mergek(int l,int r,vector<ListNode*> &A){
    if(l>r)return NULL;
    if(l==r)return A[l];
    int m=(l+r)>>1;
    return merge(mergek(l,m,A),mergek(m+1,r,A));

}
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    if(A.size()==0)return NULL;
    if(A.size()==1)return A[0];
    int n=A.size();
    return mergek(0,n-1,A);
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
