/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    if(!A||A->next==NULL)return NULL;
    ListNode *p1,*p2;
    p1=A;
    p2=A->next;
    int y=0;
    while(p2&&p2->next&&p1){
        if(p1==p2){
            y=1;
            break;
        }
        p2=p2->next->next;
        p1=p1->next;
    }
    if(!y)return NULL;
    p1=p1->next;
    y=1;
    while(p1!=p2){
    p1=p1->next;
    ++y;
    }
    p1=A;
    p2=A;
    while(y--)
    p2=p2->next;
    while(p1!=p2){
        p1=p1->next;
        p2=p2->next;
    }
    return p1;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
