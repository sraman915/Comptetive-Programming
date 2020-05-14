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
    ListNode *right,*down;
    ListNode(int x) {
        val = x;
        right = down = NULL;
    }
};

ListNode* merge(ListNode* a, ListNode* b ){
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    ListNode* result;
    if (a->val < b->val) {
        result = a;
        result->down = merge( a->down, b );
    }
    else{
        result = b;
        result->down = merge( a, b->down );
    }
    return result;
}


ListNode* flatten (ListNode* root) {
    if (root == NULL || root->right == NULL)
        return root;
    return merge( root, flatten(root->right) );
}

int32_t main(){
sp;
freopen("input2.txt","r",stdin);
freopen("output2.txt","w",stdout);
int t;
cin>>t;
while(t--){
int n;
cin>>n;
ListNode *head=NULL;
ListNode *prev=NULL;
for(int i=0; i<n; ++i){
int m;
cin>>m;
ListNode *prev1=NULL;
while(m--){
int x;
cin>>x;
ListNode *temp=new ListNode(x);
if(head==NULL)
head=temp;

if(prev1==NULL){
if(prev)prev->right=temp;
prev=temp;
}
else prev1->down=temp;
prev1=temp;
}
}

ListNode *flat=flatten(head);
ListNode *temp=flat;
int yy=0;
while(temp){
if(yy)cout<<"-> ";
cout<<temp->val<<" ";
temp=temp->down;
yy=1;
}
temp=flat;
while(temp){
flat=temp->down;
delete(temp);
temp=flat;
}
cout<<"\n";
}
return 0;}

