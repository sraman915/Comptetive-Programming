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
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

ListNode *type0(ListNode* head,int x){
ListNode *temp = new ListNode(x);

if(head==NULL){
   head=temp;
}
else{
temp->next=head;
head=temp;
}
return head;
}

ListNode *type1 (ListNode* head,int x){
ListNode *temp = new ListNode(x);

if(head==NULL){
   head=temp;
}
else{
ListNode *h=head;
while(h->next){
    h=h->next;
}
h->next=temp;
}
return head;
}


ListNode *type2 (ListNode* head,int x,int index){
ListNode *temp = new ListNode(x);
ListNode *prev=head;
assert(x>0);
int y=0;
--index;
while(y<index){
   ++y;
   prev=prev->next;
   assert(prev!=NULL);
}
ListNode *temp1=prev->next;
prev->next=temp;
temp->next=temp1;
return head;
}

ListNode *type3 (ListNode* head,int x){
ListNode *prev=NULL;
ListNode *curr=head;
ListNode *next=head->next;
if(x==0){
   head=next;
   delete(curr);
}
else{
    int index=0;
    while(index<x){
    prev=curr;
    next=next->next;
    curr=curr->next;
    ++index;
    }
    prev->next=next;
    delete(curr);
}
return head;
}

ListNode *designList(vector<vector<int> > a){
int numberofnodes=0;
ListNode *head=NULL;
int n=a.size();
for(int i=0; i<n; ++i){
int type=a[i][0];
assert(type>=0&&type<=3);

if(type==0){
assert(a[i][1]>=1&&a[i][1]<=1000000000);
assert(a[i][2]==-1);
head=type0(head,a[i][1]);
++numberofnodes;
}

else if(type==1){
assert(a[i][1]>=1&&a[i][1]<=1000000000);
assert(a[i][2]==-1);
head=type1(head,a[i][1]);
++numberofnodes;
}

else if(type==2){
assert(a[i][1]>=1&&a[i][1]<=1000000000);
int index=a[i][2];
if(index==0){
 head=type0(head,a[i][1]);
 ++numberofnodes;
}
else if(index==numberofnodes){
    head=type1(head,a[i][1]);
    ++numberofnodes;
}
else if(index>0&&index<n){
    head=type2(head,a[i][1],a[i][2]);
    ++numberofnodes;
}
}
else{
int index=a[i][1];
if(index<numberofnodes){
head=type3(head,a[i][1]);
--numberofnodes;
}
}
}
return head;
}

int32_t main(){
sp;
freopen("input1.txt","r",stdin);
freopen("output1.txt","w",stdout);
int t;
cin>>t;
while(t--){
int q,x;
cin>>q>>x;
vector<vector<int> > a(q,vector<int> (3));
for(int i=0; i<q; ++i){
  cin>>a[i][0]>>a[i][1]>>a[i][2];
}
assert(q>=1&&q<=1000);
assert(x==3);
ListNode *head=designList(a);
int z=0;
while(head){
if(z&&head)cout<<"-> ";
cout<<head->val<<" ";
z=1;
head=head->next;
}
cout<<"\n";
}
return 0;}

