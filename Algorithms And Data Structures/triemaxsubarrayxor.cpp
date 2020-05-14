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

struct trie{
    int k;
    trie *a[2];
    trie(){
        k=0;
        a[0]=NULL;
        a[1]=NULL;
    }
};


void insertt(trie *root,int val){
    trie *temp=root;
    for(int i=30; i>=0; --i){
        int curr=((val>>i)&1);
        if(!temp->a[curr])
            temp->a[curr]=new trie();
        temp=temp->a[curr];
    }
    temp->k=val;
}

int query(trie *root, int val){
    trie *temp=root;
    for(int i=30; i>=0; --i){
        int curr=((val>>i)&1);
        if(temp->a[curr^1])
            temp=temp->a[curr^1];
        else
            temp=temp->a[curr];
    }
    return (val^temp->k);
}

int maxsubarrayxor(int *a,int n){
    trie *root=new trie();
    int ans=0,val=0;
    for(int i=0; i<n; ++i){
        val=val^a[i];
        ans=max(ans,val);
        insertt(root,val);
        ans=max(ans,query(root,val));
    }
    return ans;
}

int32_t main(){
sp;
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; ++i)
        cin>>a[i];
    cout<<maxsubarrayxor(a,n);
    return 0;
}
