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

struct node{
    int data;
    node *left,*right;
    node(int x){
        data=x;
        left=NULL;
        right=NULL;
}
};


node* deserialize(vector<int> &a){
    vector<node*> nodes;

    //Parse the searlized data
    while(!a.empty()){
    int x=a.back();
    a.pop_back();
    if(x==-1)nodes.push_back(NULL);
    else nodes.push_back(new node(x));
    }
    int parentIndex = 0;
    for(int i = 1; i < nodes.size() && i > parentIndex; i += 2){
        nodes[parentIndex]->left = nodes[i];
        nodes[parentIndex]->right = nodes[i+1];
        while(++parentIndex < nodes.size() && nodes[parentIndex] == NULL);
    }
    return nodes[0];
}

int isLeaf(struct node *node) {
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right == NULL)
        return 1;
    return 0;
}

int isSumTree(node* node) {
    int ls;
    int rs;
    if(node == NULL || isLeaf(node))
        return 1;

    if( isSumTree(node->left) && isSumTree(node->right)) {
        if(node->left == NULL)
            ls = 0;
        else if(isLeaf(node->left))
            ls = node->left->data;
        else
            ls = 2*(node->left->data);
        if(node->right == NULL)
            rs = 0;
        else if(isLeaf(node->right))
            rs = node->right->data;
        else
            rs = 2*(node->right->data);
        return(node->data == ls + rs);
    }

    return 0;
}

int checksumtree(node *root){
if(isSumTree(root))
    return 1;
return 0;
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
vector<int> a(n);
for(int i=0; i<n; ++i){
cin>>a[i];
if(a[i]!=-1)
assert(a[i]>=0&&a[i]<=1000000000);
}
reverse(a.begin(),a.end());
node *root=NULL;
root=deserialize(a);
if(checksumtree(root))
    cout<<"1\n";
    else cout<<"0\n";


}
return 0;}

