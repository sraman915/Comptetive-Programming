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




int isBSTUtil(node* node, int min, int max)  {
    if (node==NULL)
        return 1;
    if (node->data < min || node->data > max)
        return 0;
    return
        isBSTUtil(node->left, min, node->data-1) && isBSTUtil(node->right, node->data+1, max);
}


void inorder(node *root,vector<int> &a){
if(root==NULL)
    return;
inorder(root->left,a);
a.push_back(root->data);
inorder(root->right,a);
}


vector<int> mergetwobst(node *root1, node *root2)  {
    stack<node *> s1;
    node *current1 = root1;
    stack<node *> s2;
    vector<int> ans;
    node *current2 = root2;
    if (root1 == NULL) {
        inorder(root2,ans);
        return ans;
    }
    if (root2 == NULL)  {
        inorder(root1,ans);
        return ans;
    }

    while (current1 != NULL || !s1.empty() ||  current2 != NULL || !s2.empty())  {
        if (current1 != NULL || current2 != NULL )  {
            if (current1 != NULL)  {
                s1.push(current1);
                current1 = current1->left;
            }
            if (current2 != NULL)  {
                s2.push(current2);
                current2 = current2->left;
            }

        }
        else{
            if (s1.empty())  {
                while (!s2.empty())  {
                    current2 = s2.top();
                    s2.pop();
                    current2->left = NULL;
                    inorder(current2,ans);
                }
                return ans;
            }
            if (s2.empty())  {
                while (!s1.empty())  {
                    current1 = s1.top();
                    s1.pop();
                    current1->left = NULL;
                    inorder(current1,ans);
                }
                return ans;
            }
            current1 = s1.top();
            s1.pop();
            current2 = s2.top();
            s2.pop();
            if (current1->data < current2->data)  {
                ans.push_back(current1->data);
                current1 = current1->right;
                s2.push(current2);
                current2 = NULL;
            }
            else{
                ans.push_back(current2->data);
                current2 = current2->right;
                s1.push(current1);
                current1 = NULL;
            }
        }
    }
    return ans;
}

vector<int> writetestcase(node *root1,node *root2){
vector<int> a;
inorder(root1,a);
inorder(root2,a);
sort(a.begin(),a.end());
return a;
}

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
int n,m;
cin>>n;
vector<int> v1(n);
for(int i=0; i<n; ++i)
    cin>>v1[i];
reverse(v1.begin(),v1.end());
cin>>m;
vector<int> v2(m);
for(int i=0; i<m; ++i)
    cin>>v2[i];
reverse(v2.begin(),v2.end());
node *root1=deserialize(v1);
node *root2=deserialize(v2);
assert(isBSTUtil(root1,INT_MIN,INT_MAX)==1);
assert(isBSTUtil(root2,INT_MIN,INT_MAX)==1);
vector<int> ans=writetestcase(root1,root2);
for(auto &it:ans)cout<<it<<" ";
cout<<"\n";
}
return 0;}

