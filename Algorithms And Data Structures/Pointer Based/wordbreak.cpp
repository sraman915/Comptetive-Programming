#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

struct trie{
int flag;
trie *a[26];
};

trie *root;
trie *get(){
trie *temp=new trie;
temp->flag=0;
for(int i=0; i<26; ++i)
    temp->a[i]=NULL;
return temp;
}

void insert(trie *root,string &s){
for(int i=0; i<s.size(); ++i){
    int x=s[i]-'a';
    if(!root->a[x])
        root->a[x]=get();
    root=root->a[x];
}
root->flag=1;
}

bool query(trie *root,string &s){
for(int i=0; i<s.size(); ++i){
    int x=s[i]-'a';
    if(!root->a[x])return 0;
    root=root->a[x];
}
return root->flag;
}

void fun(trie *root,vector<string> &v){
for(int i=0; i<v.size(); ++i)
    insert(root,v[i]);
}
vector<string> p;

void realfun(int i,trie *root,string &s,string &z){
    if(i>=s.size()){
        if(!z.empty())p.pb(z);
        return;
    }
    for(int j=i; j<s.size(); ++j){
        string xx=s.substr(i,j+1-i);
        if(query(root,xx)){
            for(int k=i; k<=j;++k)
                z.pb(s[k]);
            if(j+1<s.size())z.pb(' ');
            realfun(j+1,root,s,z);
            if(j+1<s.size())z.pop_back();
            for(int k=i; k<=j; ++k)
            z.pop_back();
        }
    }
}



int main(){
sp;
int n;
cin>>n;
vector<string> v;
string s;
for(int i=0; i<n; ++i){
    cin>>s;
    v.pb(s);
}
root=get();
fun(root,v);
cin>>s;
string z;
realfun(0,root,s,z);
for(auto &it:p)cout<<it<<"\n";

return 0;}
