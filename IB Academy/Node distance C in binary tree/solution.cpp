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

unordered_map<node*, node*> uMap;

void mapParentNode(node* root,node* parent) {
    if (!root)
        return;
    uMap[root]=parent;
    mapParentNode(root->left,root);
    mapParentNode(root->right,root);
}

vector<int> solveit(node *root,node* target,int k){
    uMap.clear();
    vector<int> res;
    queue<node*> q;
    unordered_set<node*> visited;
    node* curr;
    int width=0;
    int level=0;
    if(root==NULL)
        return res;
    if(k==0){
        res.push_back(target->data);
        return res;
    }
    mapParentNode(root,NULL);
    q.push(target);
    visited.insert(target);
    while (!q.empty()) {
                width = q.size();
                for (int i=0; i<width; ++i){
                    curr = q.front();
                    q.pop();
                    if (level == k) {
                        res.push_back(curr->data);
                    }
                    else {
                        if ( uMap[curr] && (visited.find(uMap[curr]) == visited.end()) ) {
                            q.push(uMap[curr]);
                            visited.insert(uMap[curr]);
                        }
                        if ( curr->left && (visited.find(curr->left) == visited.end()) ) {
                            q.push(curr->left);
                            visited.insert(curr->left);
                        }
                        if ( curr->right && (visited.find(curr->right) == visited.end()) ) {
                            q.push(curr->right);
                            visited.insert(curr->right);
                        }
                    }
                }
                level++;
            }

    return res;
}

vector<int> doit(node *root,int target,int k){
node *targetpointer = NULL;
queue<node *> q;
q.push(root);
    while(!q.empty()){
        node *temp=q.front();
        q.pop();
    if(temp->data==target){
        targetpointer=temp;
        break;
    }
    if(temp->left)
        q.push(temp->left);
    if(temp->right)
        q.push(temp->right);
}
assert(targetpointer!=NULL);
return solveit(root,targetpointer,k);
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
vector<int> v(n);
for(int i=0; i<n; ++i)cin>>v[i];
reverse(v.begin(),v.end());
int target,k;
cin>>target>>k;
node *root=deserialize(v);
vector<int> ans=doit(root,target,k);
sort(ans.begin(),ans.end());
for(auto &it:ans)
    cout<<it<<" ";
cout<<"\n";
}
return 0;}

