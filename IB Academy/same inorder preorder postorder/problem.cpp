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

void recursivepreorder(node *root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    recursivepreorder(root->left);
    recursivepreorder(root->right);
}

void recursiveinorder(node *root){
    if(root==NULL)
        return;
    recursiveinorder(root->left);
    cout<<root->data<<" ";
    recursiveinorder(root->right);
}

void recursivepostorder(node *root){
    if(root==NULL)
        return;
    recursivepostorder(root->left);
    recursivepostorder(root->right);
    cout<<root->data<<" ";
}

void del(node *root){
    if(root==NULL)
        return ;
    del(root->left);
    del(root->right);
    delete(root);
}

int noofnodes;

node* constructtree(int n,int y){
   queue<node*> q;
   node *root=NULL;
   vector<int> v(n);
   int prev=1;
   for(int i=0; i<n; ++i){
        v[i]=prev+1+rng(10);
        prev=v[i];
    }
    random_shuffle(v.begin(),v.end());
    root=new node(v[0]);
    q.push(root);
    noofnodes=n;
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

void random(int n,int y){
vector<int> v(n);
int prev=1;
for(int i=0; i<n; ++i){
    v[i]=prev+1+rng(12);
    prev=v[i];
}
random_shuffle(v.begin(),v.end());
cout<<n<<" ";
for(auto &it:v)cout<<it<<" ";
cout<<"\n";
cout<<n<<" ";
random_shuffle(v.begin(),v.end());
for(auto &it:v)cout<<it<<" ";
cout<<"\n";
cout<<n<<" ";
random_shuffle(v.begin(),v.end());
for(auto &it:v)cout<<it<<" ";
cout<<"\n";
}


int32_t main(){
sp;
srand(chrono::high_resolution_clock::now().time_since_epoch().count());
freopen("input1.txt","w",stdout);
    int t=24;
    cout<<t<<"\n";
    int z=50,y=0;
    for(int ii=1; ii<=t; ++ii){
    int xxx=rng(2);
    if(xxx==0&&z){
    --z;
    random(3+rng(12),4000);
    continue;
    }
        noofnodes=0;
        node *root=constructtree(3+rng(12),4000);
        cout<<noofnodes<<" ";
        recursivepreorder(root);
        cout<<"\n"<<noofnodes<<" ";
        recursiveinorder(root);
        cout<<"\n"<<noofnodes<<" ";
        recursivepostorder(root);
        cout<<"\n";
        del(root);
}
return 0;
}
