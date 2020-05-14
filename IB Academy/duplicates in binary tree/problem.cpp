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


mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
random_device rd;

uniform_real_distribution<double> r1(1.0,20.0);
uniform_int_distribution<int> r2(1,1000);
normal_distribution<double> r3(1.0,20.0);
exponential_distribution<double> r4(5);

int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}


struct node{
    int data;
    node *left,*right;
    node(int x){
        data=x;
        left=NULL;
        right=NULL;
}
};

node* constructtree(int n,int y){
   queue<node*> q;
   node *root=NULL;
   vector<int> v(n);
   for(int i=0; i<n; ++i)
        v[i]=rng(y);
    root=new node(v[0]);
    q.push(root);
   for(int i=1; i<n; ++i){
        node *temp=new node(v[i]);
        node *temp1=q.front();
        if(temp1->left==NULL)
            temp1->left=temp;
        else if(temp1->right==NULL)
            temp1->right=temp;
        if(temp1->left&&temp1->right)
            q.pop();
   q.push(temp);
   }
   return root;
}


/*void serialize(node *root,vector<int> &a) {
    if (root == NULL) {
    a.push_back(-1);
        return;
    }
    a.push_back(root->data);
    serialize(root->left, a);
    serialize(root->right, a);
}*/

void serialize(node *root,vector<int> &a){
queue<node *> q;
q.push(root);
while(!q.empty()){
node *temp=q.front();
q.pop();
if(temp)
a.push_back(temp->data);
else a.push_back(-1);
if(temp)q.push(temp->left);
if(temp)q.push(temp->right);
}
}

void duplicate(node *root){
node *temp=NULL;
node *curr=root;
while(curr&&curr->left&&curr->left->left){
curr=curr->left;
}
if(curr==root)
    return;
node *curr1;
curr1=root;
while(curr1->right==NULL){
curr1=curr1->right;
}
queue<pair<node *,node *> > q;
curr1->right=new node(curr->data);
q.push({curr,curr1->right});
while(!q.empty()){
node *temp=q.front().first;
node *temp1=q.front().second;
q.pop();
if(temp->left){
temp1->left=new node(temp->left->data);
q.push({temp->left,temp1->left});
}
if(temp->right){
temp1->right=new node(temp->right->data);
q.push({temp->right,temp1->right});
}
}
}


int32_t main(){
sp;
srand(chrono::high_resolution_clock::now().time_since_epoch().count());
freopen("input3.txt","w",stdout);
    int t=50;
    cout<<t<<"\n";
    int yy=t/2+2;
    for(int ii=1; ii<=t; ++ii){
       int n=5000+rng(500);
       int z=10;
       node *root=constructtree(n,z);
       int zz=rng(2);
       if(zz==0&&yy){
       duplicate(root);
       --yy;
       }
       vector<int> a;
       serialize(root,a);
       int y=0;
       for(auto &it:a)
       if(it!=-1){
       ++y;
       assert(it>=0&&it<=9);
       }
       cout<<a.size()<<" ";
       for(auto &it:a)cout<<it<<" ";
       cout<<"\n";
}
return 0;
}
