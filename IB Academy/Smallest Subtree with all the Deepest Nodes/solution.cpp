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

#define TreeNode node


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

void recursivepreorder(node *root){
    if(root==NULL)
        return;
        cout<<root->data<<" ";
    recursivepreorder(root->left);
    recursivepreorder(root->right);
}


void recursivepostorder(node *root){
    if(root==NULL)
        return;
    recursivepostorder(root->left);
    recursivepostorder(root->right);
    cout<<root->data<<" ";
}


int maxDepth = -1;
TreeNode* first ;
TreeNode* second;

void DFS(TreeNode* root, int depth) {
    if (root==NULL)
        return;
    if (root->left==NULL && root->right==NULL) {
        if (depth > maxDepth) {
            first = root;
            second = NULL;
            maxDepth = depth;
        }
        else if (depth == maxDepth) {
            second = root;
        }
    }
    DFS(root->left, depth + 1);
    DFS(root->right, depth + 1);
}

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root)
        return NULL;
    if (p == root || q == root)
        return root;
    auto left = lca(root->left, p, q);
    auto right = lca(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}

TreeNode* solve(TreeNode* root) {
    if (!root)
        return root;

    maxDepth = -1;
    first = NULL;
    second = NULL;
    DFS(root, 0);
    return !second ? first : lca(root, first, second);
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
for(int i=0; i<n; ++i)cin>>a[i];
reverse(a.begin(),a.end());
node *root=NULL;
root=deserialize(a);
node *nroot=solve(root);
cout<<"Returned tree's PreOrder traversal : [ ";
recursivepreorder(nroot);
cout<<"]";
cout<<" ## ";
cout<<"Returned tree's PostOrder traversal : [ ";
recursivepostorder(nroot);
cout<<"]";
cout<<"\n";
}
return 0;}

