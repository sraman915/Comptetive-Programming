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

node* constructtree(int n,int y,int pp){
   queue<node*> q;
   node *root=NULL;
   vector<int> v(n);
   for(int i=0; i<n; ++i)
        v[i]=1+rng(y);
    root=new node(v[0]);
    q.push(root);
   for(int i=1; i<n; ++i){
        node *temp=new node(v[1]);
        node *temp1=q.front();
        if(temp1->left==NULL)
            temp1->left=temp;
        else if(temp1->right==NULL)
            temp1->right=temp;
        if(temp1->left&&temp1->right)
            q.pop();
   q.push(temp);
   }
   if(pp){
   node *r=root;
   while(!q.empty())q.pop();
   q.push(r);
   while(!q.empty()){
   node *temp=q.front();
   q.pop();
   if(temp->left||temp->right)
         temp->data=0;
   if(temp->left)q.push(temp->left);
   if(temp->right)q.push(temp->right);
   }
   }
   return root;
}



int toSumTree(struct node *node) {
    if(node == NULL)
      return 0;
    if(node->left==NULL&&node->right==NULL)
        return node->data;
    int old_val = node->data;
    node->data = toSumTree(node->left) + toSumTree(node->right);
    return node->data + node->data+old_val;
}


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


int32_t main(){
sp;
srand(chrono::high_resolution_clock::now().time_since_epoch().count());
freopen("input3.txt","w",stdout);
int t=80;
cout<<t<<"\n";
for(int ii=1; ii<=t; ++ii){
int n=30+rng(20);
int z=9;
node *root=NULL;
int minn=t/2+rng(t/4+1);
if(ii<=minn){
root=constructtree(n,z,1);
toSumTree(root);
}
else
root=constructtree(n,z,0);
vector<int> a;
serialize(root,a);
int zz=0;
cout<<a.size()<<" ";
for(auto &it:a){
cout<<it<<" ";
if(it!=-1)++zz;
}
assert(zz==n);
cout<<"\n";
}
return 0;}
