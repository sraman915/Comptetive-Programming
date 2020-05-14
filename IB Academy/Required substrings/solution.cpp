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


struct AhoCorasick {
  static const int UNDEF = 0;
  static const int MAXN = 360;
  static const int CHARSET = 26;

  int end;
  int tag[MAXN];
  int fail[MAXN];
  int trie[MAXN][CHARSET];

  void init() {
    tag[0] = UNDEF;
    fill(trie[0], trie[0] + CHARSET, -1);
    end = 1;
  }

  void add(int m, const int* s, int t) {
    int p = 0;
    for (int i = 0; i < m; ++i) {
      if (trie[p][*s] == -1) {
        tag[end] = UNDEF;
        fill(trie[end], trie[end] + CHARSET, -1);
        trie[p][*s] = end++;
      }
      p = trie[p][*s];
      ++s;
    }
    tag[p] = t;
  }

  void build() {
    queue<int> bfs;
    fail[0] = 0;
    for (int i = 0; i < CHARSET; ++i) {
      if (trie[0][i] != -1) {
        fail[trie[0][i]] = 0;
        bfs.push(trie[0][i]);
      } else {
        trie[0][i] = 0;
      }
    }
    while (!bfs.empty()) {
      int p = bfs.front();
      tag[p] |= tag[fail[p]];
      bfs.pop();
      for (int i = 0; i < CHARSET; ++i) {
        if (trie[p][i] != -1) {
          fail[trie[p][i]] = trie[fail[p]][i];
          bfs.push(trie[p][i]);
        } else {
          trie[p][i] = trie[fail[p]][i];
        }
      }
    }
  }
};

const int MAXN = 6;
const int MAXL = 60;
const int MOD = 1000000009;

int a[MAXL];
int dp[MAXL][AhoCorasick::MAXN][1 << MAXN];

int countsubstrings(vector <string> words, int C, int L) {
  int n = words.size();
  AhoCorasick ac;
  ac.init();
  for (int i = 0; i < n; ++i) {
    int m = words[i].length();
    for (int j = 0; j < m; ++j) {
      a[j] = words[i][j] - 'a';
    }
    ac.add(m, a, 1 << i);
  }
  ac.build();

  fill(dp[0][0], dp[L + 1][0], 0);
  dp[0][0][ac.tag[0]] = 1;
  for (int i = 0; i < L; ++i) {
    for (int j = 0; j < ac.end; ++j) {
      for (int k = 0; k < (1 << n); ++k) {
        if (dp[i][j][k] != 0) {
          for (int t = 0; t < AhoCorasick::CHARSET; ++t) {
            int jj = ac.trie[j][t];
            int kk = k | ac.tag[jj];
            dp[i + 1][jj][kk] = (dp[i + 1][jj][kk] + dp[i][j][k]) % MOD;
          }
        }
      }
    }
  }

  int ans = 0;
  for (int j = 0; j < ac.end; ++j) {
    for (int k = 0; k < (1 << n); ++k) {
      if (__builtin_popcount(k) == C) {
        ans = (ans + dp[L][j][k]) % MOD;
      }
    }
  }
  return ans;
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
vector<string> A(n);
for(int i=0; i<n; ++i)
    cin>>A[i];
int C,L;
cin>>C>>L;
assert(C>=0&&C<=n);
assert(L>=1&&L<=50);
int ans=countsubstrings(A,C,L);
cout<<ans<<"\n";
}
return 0;}
