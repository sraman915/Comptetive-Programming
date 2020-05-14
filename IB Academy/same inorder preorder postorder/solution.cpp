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

/*
struct node{
    int data;
    node *left,*right;
    node(int x){
        data=x;
        left=NULL;
        right=NULL;
}
};

int find(vector<int> &in,int l,int r,int x){
     for(int i=l; i<=r; ++i)
     if(in[i]==x)return i;
     return -1;
 }

int j=0;
node *doit(vector<int> &in,vector<int> &pre,int l,int r){
     if(l>r)return NULL;
     node *temp=NULL;
     if(j<in.size())
        temp=new node(pre[j++]);
     if(l==r)return temp;
     int m=find(in,l,r,temp->data);
     temp->left=doit(in,pre,l,m-1);
     temp->right=doit(in,pre,m+1,r);
     return temp;
 }

node *buildtreefrominorderandpreorder(vector<int> &in,vector<int> &pre){
    int n=in.size();
    j=0;
    return doit(in,pre,0,n-1);
}


int checkpostorder(node *root,vector<int> &post,int index){
    if(root==NULL)
        return index;
    index=checkpostorder(root->left,post,index);
    index=checkpostorder(root->right,post,index);
    if (root->data!=post[index])
        return -1;
    else
        ++index;
    return index;
}

void del(node *root){
    if(root==NULL)
        return ;
    del(root->left);
    del(root->right);
    delete(root);
}


int solve(vector<int> &pre,vector<int> &in,vector<int> &post){
    node *root=buildtreefrominorderandpreorder(in,pre);
    int n=post.size();
    int reach=checkpostorder(root,post,0);
    del(root);
    if(reach==n)
        return 1;
    return 0;
}*/

int checktree(int *preorder,int *inorder, int *postorder, int len) {
    if (len== 0)
        return 1;
    if (len == 1)
        return (preorder[0] == inorder[0]) && (inorder[0] == postorder[0]);
    int idx = -1;
    for (int i = 0; i < len; ++i)
        if (inorder[i] == preorder[0]) {
            idx = i;
            break;
        }
    if (idx == -1)
        return 0;
    int ret1 = checktree(preorder + 1, inorder, postorder, idx);
    int ret2 = checktree(preorder + idx + 1, inorder + idx + 1, postorder + idx, len - idx - 1);
    return (ret1 && ret2);
}

int32_t main(){
sp;
freopen("input1.txt","r",stdin);
freopen("output1.txt","w",stdout);
int t;
cin>>t;
while(t--){
    int n,n1,n2,n3;
    cin>>n1;
    n=n1;
    assert(n1>=1&&n1<=1000);
    int preorder[n];
    int inorder[n];
    int postorder[n];
    for(int i=0; i<n; ++i)
        cin>>preorder[i];
    cin>>n2;
    assert(n2==n);
    for(int i=0; i<n; ++i)
        cin>>inorder[i];
    cin>>n3;
    assert(n3==n);
    for(int i=0; i<n; ++i)
        cin>>postorder[i];
    if(checktree(preorder,inorder,postorder,n))
        cout<<"1\n";
    else
        cout<<"0\n";
}
return 0;}
