#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (long long)1000000007
#define f first
#define s second
#define debug1(x) cerr<<x<<"\n"
#define debug2(x,y) cerr<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<"\n"
#define nl cerr<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cerr<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 500005


struct ListNode {
      int val;
      ListNode *next,*prev;
      ListNode(int x) : val(x), next(NULL) , prev(NULL) {}
};

ListNode *split(ListNode *head)  {
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast->next && fast->next->next)  {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *temp = slow->next;
    slow->next = NULL;
    return temp;
}

ListNode *merge(ListNode *first, ListNode *second)  {
    if (!first)
        return second;

    if (!second)
        return first;

    if (first->val < second->val)  {
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else{
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

ListNode *mergeSort(ListNode *head)  {
    if (!head || !head->next)
        return head;
    ListNode *second = split(head);

    head = mergeSort(head);
    second = mergeSort(second);

    return merge(head,second);
}

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
int n;
cin>>n;
ListNode *head=NULL,*curr=NULL;
assert(n>=1&&n<=100000);
for(int i=1; i<=n; ++i){
      int x;
      cin>>x;
      ListNode *temp=new ListNode(x);
      if(head==NULL){
      head=temp;
      curr=temp;
      }
      else{
      curr->next=temp;
      temp->prev=curr;
      curr=temp;
      }
}
head=mergeSort(head);
int yy=0;
while(head){
if(yy)cout<<"-> ";
cout<<head->val<<" ";
curr=head;
head=head->next;
yy=1;
}
cout<<"\n";
yy=0;
while(curr){
if(yy)cout<<"<- ";
cout<<curr->val<<" ";
yy=1;
head=curr;
curr=curr->prev;
}
while(head){
curr=head;
head=head->next;
delete(curr);
}

cout<<"\n";
}
return 0;}

