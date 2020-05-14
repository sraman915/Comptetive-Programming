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
        k  = 0;
        a[0] = a[1] = NULL;
    }
};

void insertt(trie *root, int val){
    trie *temp = root;
    for(int i = 31; i >= 0; --i){
        bool curr = (val & (1<<i));
        if(!temp->a[curr])
            temp->a[curr] = new trie();
        temp = temp->a[curr];
    }
    temp->k = val;
}

int maxxorq(trie *root, int val){
    trie *temp = root;
    for(int i = 31; i >= 0; --i){
        bool curr = (val&(1<<i));
        if(temp->a[1-curr])
            temp = temp->a[1-curr];
        else if(temp->a[curr])
            temp = temp->a[curr];
    }
    return (val ^ temp->k);
}

int mxor(int b[],int n){
    trie *root = new trie();
    int ans = -1;
    insertt(root,0);
    int sum = 0;
    for(int i = 0; i < n; ++i){
        sum ^= b[i];
        insertt(root,sum);
        ans = max(maxxorq(root,sum),ans);
    }
    return ans;
}

int32_t main(){
sp;
    int n=4;
    int b[]={9,5,3,9};
    cout<<mxor(b,n);
    return 0;
}
