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
vector<vector<int> > paths(node* A) {
    node *temp,*temp1;
    queue<node *> q;
    unordered_map<node *,node *> mp;
    mp[A]=NULL;
    vector<vector<int> > vv;
    vector<int> v;
    if(!A)return vv;
    q.push(A);
    while(!q.empty()){
        temp=q.front();
        q.pop();
        temp1=temp;
        if(temp->left==NULL&&temp->right==NULL){
            v.clear();
            while(temp!=NULL){
                v.push_back(temp->data);
                temp=mp[temp];
            }
            reverse(v.begin(),v.end());
            vv.push_back(v);
            continue;
        }
        if(temp->left){
        q.push(temp->left);
        mp[temp->left]=temp1;
        }
         if(temp->right){
        q.push(temp->right);
        mp[temp->right]=temp1;
        }
    }
    return vv;
}

void print(vector<vector<int> > &vv){
int n=vv.size();
for(int i=0; i<n; ++i){
cout<<"[";
for(auto &it:vv[i])cout<<it<<" ";
cout<<"] ";
}
cout<<"\n";
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
vector<vector<int>  > vv=paths(root);
print(vv);
}
return 0;}

