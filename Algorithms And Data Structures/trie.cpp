#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005

string s;

struct trie{
bool flag;
trie *a[3];
};

trie *get(){
trie *temp=new trie;
temp->flag=0;
temp->a[0]=temp->a[1]=temp->a[2]=NULL;
return temp;
}

void insert(trie *root){
for(int i=0; s[i]; ++i){
    int z=s[i]-'a';
    if(!root->a[z])
        root->a[z]=get();
    root=root->a[z];
}
root->flag=1;
}

bool query(int i,trie *root,int y){
if(i==s.size()){
    if(!y)return y;
    return root->flag;
}
int z=s[i]-'a';
int p=0;
if(root->a[z])p|=query(i+1,root->a[z],y);
if(y==0&&p==0){
    for(int j=0; j<3; ++j)
        if(j!=z&&root->a[j])
            p|=query(i+1,root->a[j],1);
}
return p;
}

int main(){
sp;
int n,m;
cin>>n>>m;
trie *root=get();
for(int i=0; i<n; ++i){
    cin>>s;
    insert(root);
}
for(int i=0; i<m; ++i){
    cin>>s;
    if(query(0,root,0))cout<<"YES\n";
    else cout<<"NO\n";
}
return 0;}
