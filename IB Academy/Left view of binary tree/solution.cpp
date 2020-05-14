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


vector<int> leftview(node *root){
    vector<int> ans;
    queue<node *> q;
    if(root==NULL)
        return ans;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *temp=q.front();
        if(temp){
            ans.push_back(temp->data);
            while(q.front()!=NULL){
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                q.pop();
                temp=q.front();
            }
            q.push(NULL);
        }
    q.pop();
    }
return ans;
}

void printlevelorder(node *root){
queue<node *> q;
if(!root)return;
q.push(root);
q.push(NULL);
while(!q.empty()){
int zz=0;
while(q.front()!=NULL){
node *temp=q.front();
q.pop();
zz=1;
cout<<temp->data<<" ";
if(temp->left)q.push(temp->left);
if(temp->right)q.push(temp->right);
}
cout<<"\n";
q.pop();
if(zz)q.push(NULL);
}
}

int32_t main(){
sp;
freopen("input1.txt","r",stdin);
freopen("output1.txt","w",stdout);
int t;
cin>>t;
while(t--){
int n;
cin>>n;
vector<int> v(n);
for(int i=0; i<n; ++i)cin>>v[i];
reverse(v.begin(),v.end());
node *root=deserialize(v);
//printlevelorder(root);
vector<int> ans=leftview(root);
for(auto &it:ans)
    cout<<it<<" ";
cout<<"\n";
}
return 0;}

