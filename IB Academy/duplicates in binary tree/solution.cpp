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

unordered_set<string> subtrees;
string MARKER ="$";

string check(node *root) {
    string s = "";
    if (root == NULL)
        return s + MARKER;
    string lStr = check(root->left);
    if (lStr.compare(s) == 0)
       return s;
    string rStr = check(root->right);
    if (rStr.compare(s) == 0)
       return s;
    string p;
    p.push_back(root->data+'0');
    s = s + p + lStr + rStr;
    if (s.length() > 3 &&subtrees.find(s) != subtrees.end())
       return "";
    subtrees.insert(s);
    return s;
}

int checkduplicatesubtree(node *root){
    subtrees.clear();
    string ch1=check(root);
    if(ch1.compare("")==0)
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
vector<int> v(n);
for(int i=0; i<n; ++i)
    cin>>v[i];
reverse(v.begin(),v.end());
node *root=deserialize(v);
int ans=checkduplicatesubtree(root);
cout<<ans;
cout<<"\n";
}
return 0;}

