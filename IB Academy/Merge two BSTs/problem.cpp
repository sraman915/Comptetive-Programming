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
#define mxn 1000000

int c[mxn];

void pre(int start){
for(int i=0; i<mxn;++i)
c[i]=start+i+1;
random_shuffle(c,c+mxn);
}

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
        v[i]=1+rng(y);
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


vector<node*> v;

void convertobst(node *root){
if(root==NULL)
    return;
convertobst(root->left);
v.push_back(root);
convertobst(root->right);
}

int isBSTUtil(node* node, int min, int max)  {
    if (node==NULL)
        return 1;
    if (node->data < min || node->data > max)
        return 0;
    return
        isBSTUtil(node->left, min, node->data-1) && isBSTUtil(node->right, node->data+1, max);
}


int32_t main(){
sp;
srand(chrono::high_resolution_clock::now().time_since_epoch().count());
freopen("input3.txt","w",stdout);
pre(2);
int index=0;
    int t=10;
    cout<<t<<"\n";
    for(int ii=1; ii<=t; ++ii){
       int n=50000+rng(50000);
       int m=50000+rng(50000);
       int z=18;
       index=0;
       vector<int> v1;
       index=rng(2000);
       for(int i=0; i<n+m; ++i)v1.push_back(c[index+i]);
       sort(v1.rbegin(),v1.rend());
       node *root1=constructtree(n,z);
       node *root2=constructtree(m,z);
       v.clear();
       convertobst(root1);
       assert(v.size()==n);
       for(int i=0;i<v.size(); ++i){
       v[i]->data=v1.back();
       v1.pop_back();
       }
       assert(isBSTUtil(root1,INT_MIN,INT_MAX)==1);
       v.clear();
       convertobst(root2);
       assert(v.size()==m);
       for(int i=0;i<v.size(); ++i){
       v[i]->data=v1.back();
       v1.pop_back();

       }
       assert(isBSTUtil(root2,INT_MIN,INT_MAX)==1);
       vector<int> a,b;
       serialize(root1,a);
       serialize(root2,b);
       int y=0;
       for(auto &it:a)
       if(it!=-1)++y;
       assert(y==n);
       y=0;
       for(auto &it:b)
       if(it!=-1)++y;
       assert(y==m);
       cout<<a.size()<<" ";
       for(auto &it:a)cout<<it<<" ";
       cout<<"\n";
       cout<<b.size()<<" ";
       for(auto &it:b)cout<<it<<" ";
       cout<<"\n";
}
return 0;
}
