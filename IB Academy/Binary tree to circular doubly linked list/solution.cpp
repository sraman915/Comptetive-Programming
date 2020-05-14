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

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *concatenate(TreeNode *leftList, TreeNode *rightList) {
    if (leftList == NULL)
              return rightList;
    if (rightList == NULL)
              return leftList;

    TreeNode *leftLast = leftList->left;

    TreeNode *rightLast = rightList->left;
    if(leftLast)
         leftLast->right = rightList;
    rightList->left = leftLast;
    leftList->left = rightLast;
    if(rightLast)
            rightLast->right = leftList;
    return leftList;
}

TreeNode *bTreeToCList(TreeNode *root) {
    if (root == NULL)
        return NULL;
    TreeNode *left = bTreeToCList(root->left);
    TreeNode *right = bTreeToCList(root->right);
    root->left = root->right = root;
    return concatenate(concatenate(left, root), right);
}

TreeNode *solve(TreeNode *A){
return bTreeToCList(A);
}

void inorder(TreeNode *root){
if(root==NULL)
return;
inorder(root->left);
cout<<root->val<<" ";
inorder(root->right);
}

void traversal(TreeNode *root){
if(root==NULL)return;
TreeNode *temp=root;
do{
cout<<root->val<<" ";
root=root->right;
}while(temp!=root&&root!=NULL);
cout<<"\n";
}

void deSerialize(TreeNode *&root,vector<int> &a) {
  if(a.empty())return;
    int val=a.back();
    a.pop_back();
    if (val == -1) return;
    root = new TreeNode(val);
    deSerialize(root->left, a);
    deSerialize(root->right, a);
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
  for(int i=0; i<n; ++i)
        cin>>a[i];
  reverse(a.begin(),a.end());
  TreeNode *root=NULL;
  deSerialize(root,a);
  root=solve(root);
  traversal(root);
}
return 0;}
