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
   return root;
}


void gen(node *root,string &s){
    if(root==NULL)
        return ;
    if(root->left&&root->right){
        s.push_back('2');
        gen(root->left,s);
        gen(root->right,s);
    }
    else if(root->left){
        s.push_back('1');
        gen(root->left,s);
    }
    else if(root->right){
        s.push_back('1');
        gen(root->right,s);
    }
    else{
    s.push_back('0');
    }
}


int32_t main(){
sp;
srand(chrono::high_resolution_clock::now().time_since_epoch().count());
freopen("input3.txt","w",stdout);
    int t=100;
    cout<<t<<"\n";
    for(int ii=1; ii<=t; ++ii){
    int n=10000;
    node *root=constructtree(n,5);
    string s;
    gen(root,s);
    assert(s.size()>=1&&s.size()<=100000);
    cout<<s<<"\n";
}
return 0;
}
