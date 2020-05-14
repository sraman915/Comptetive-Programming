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

/*void deSerialize(node *&root,vector<int> &a) {
  if(a.empty())return;
    int val=a.back();
    a.pop_back();
    if (val == -1) return;
    root = new node(val);
    deSerialize(root->left, a);
    deSerialize(root->right, a);
}*/

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

void serialize(node *root,vector<int> &a) {
    if (root == NULL) {
    a.push_back(-1);
        return;
    }
    a.push_back(root->data);
    serialize(root->left, a);
    serialize(root->right, a);
}



node *pruneUtil(struct node *root, int k, int *sum) {
    if (root == NULL)  return NULL;
    int lsum = *sum + (root->data);
    int rsum = lsum;
    root->left = pruneUtil(root->left, k, &lsum);
    root->right = pruneUtil(root->right, k, &rsum);
    *sum = max(lsum, rsum);
    if (*sum < k) {
        free(root);
        root = NULL;
    }

    return root;
}

node *prune(node *root, int k) {
    int sum = 0;
    return pruneUtil(root, k, &sum);
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

int maxDepth;
node* first;
node* second;

void dfs(TreeNode* node, int depth) {
    if (!node) return;
    if (!node->left && !node->right) {
        if (depth > maxDepth) {
            first = node, second = NULL;
            maxDepth = depth;
            }
        else if (depth == maxDepth) {
            second = node;
            }
        }
    dfs(node->left, depth + 1);
    dfs(node->right, depth + 1);
}

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return NULL;
    if (p == root || q == root)
    return root;
    auto left = lca(root->left, p, q), right = lca(root->right, p, q);
    if (left && right)
        return root;
    return left ? left : right;
}

TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    if (!root)
    return root;
    int maxDepth = 0;
    node* first = NULL;
    node* second = NULL;
    dfs(root, 0);
    return !second ? first : lca(root, first, second);
}




int32_t main(){
sp;
//freopen("input1.txt","r",stdin);
//freopen("output1.txt","w",stdout);
int t;
cin>>t;
while(t--){
int n,k;
cin>>n;
vector<int> a(n);
for(int i=0; i<n; ++i)cin>>a[i];
reverse(a.begin(),a.end());
cin>>k;
node *root=NULL;
root=deserialize(a);
if(root==NULL)test;
node *nroot=prune(root,k);
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

