/*
MORSE - Decoding Morse Sequences
https://www.spoj.com/problems/MORSE/
SOLUTION BY RAMANS SHARMA
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
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

struct trie{
int leaf=0;
trie *a[2];
trie(){
leaf=0;
a[1]=a[0]=NULL;
}
};

int give(char x){
if(x=='.')return 0;
return 1;
}

void insert(trie *root,string &s){
for(int i=0; i<s.size(); ++i){
    int z=give(s[i]);
    if(!root->a[z])
        root->a[z]=new trie();
    root=root->a[z];
}
++root->leaf;
}

int query(trie *root,string &s){
for(int i=0; i<s.size(); ++i){
    int z=give(s[i]);
    if(!root->a[z])return 0;
    root=root->a[z];
}
return root->leaf;
}

void del(trie *root){
if(root==NULL)return;
del(root->a[0]);
del(root->a[1]);
delete(root);
}

trie *root;
ll dp[10005];
ll solve(int n,string &p){
memset(dp,0,sizeof dp);
dp[n]=1LL;
trie *temp=root;
for(int i=n-1; i>-1; --i){
    temp=root;
    for(int j=i; j<n&&temp!=NULL; ++j){
        if(p[j]=='.')temp=temp->a[0];
        else temp=temp->a[1];
        if(temp==NULL)break;
        dp[i]+=(temp->leaf*dp[j+1]);
    }
}
return dp[0];
}


int main(){
sp;
string a[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
int t;
cin>>t;
while(t--){
    root=new trie();
    string p;
    cin>>p;
    int n;
    cin>>n;
    for(int i=1; i<=n; ++i){
        string x,z;
        cin>>x;
        z="";
        for(auto &it:x)z+=a[it-'A'];
        insert(root,z);
    }
    n=p.size();
    cout<<solve(n,p)<<"\n";
}
return 0;}
