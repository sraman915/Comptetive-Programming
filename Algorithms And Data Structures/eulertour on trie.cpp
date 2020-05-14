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

unordered_map<string,int> start, finish;
int p = 0;


struct trie{
    trie *a[26];
    trie(){
        for(int i = 0; i < 26; ++i)
            a[i] = NULL;
    }
};

trie *root;


void insertt(string &s){
    trie *temp = root;
    for(auto &it: s){
        int z = it-'a';
        if(temp->a[z] == NULL)
            temp->a[z] = new trie();
        temp = temp->a[z];
    }
}

void dfs(trie *root, string s1){
    trie *temp = root;
    start[s1] = ++p;
    for(int i = 0; i < 26; ++i)
        if(temp->a[i])
            dfs(temp->a[i], s1 + (char)(i + 'a'));
    finish[s1] = p;
}

int bit[mxn][26];

int read(int x, int y){
    int sum = 0;
    while(x > 0){
        sum += bit[x][y];
        x -= (x & (-x));
    }
    return sum;
}

void update(int x, int y, int val){
    while(x <= p){
        bit[x][y] += val;
        x += (x & (-x));
    }
}

unordered_map<string,int[26]> init;
unordered_map<string,int> mp;

int32_t main(){
sp;
    int n,m;
    cin>>n>>m;
    string b[n];
    root = new trie();
    for(int i = 0; i < n; ++i){
        cin>>b[i];
        ++mp[b[i]];
        insertt(b[i]);
    }
    dfs(root, "");
    for(int i = 0; i < n; ++i)
        for(auto &it: b[i])
            ++init[b[i]][it-'a'];
    int c;
    string x;
    char ch;
    while(m--){
        cin>>c>>x>>ch;
        if(c == 1){
            update(start[x], ch - 'a', 1);
            update(finish[x] + 1, ch - 'a', -1);
        }
        else if(c == 2){
            update(start[x], ch - 'a', -1);
            update(finish[x] + 1, ch - 'a', 1);
        }
        else{
            int y = read(start[x], ch - 'a');
            int z = mp[x];
            int ans = init[x][ch - 'a'];
            cout<<y<<" "<<z<<" "<<ans<<"\n";
            ans += y * z;
            cout<<ans<<"\n";
        }
    }
    return 0;
}
