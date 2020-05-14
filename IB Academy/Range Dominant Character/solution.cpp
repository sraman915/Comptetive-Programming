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

const int N = 100002;
int a[N][26];

vector<int> solveit(string A,vector<vector<int> > &B){
    int n=A.size();
    A=" "+A;
    for(int i=1; i<=n; ++i)
        for(int j=0; j<26; ++j)
            a[i][j]=0;
    for(int i=1; i<=n; ++i)
        ++a[i][A[i]-'a'];
    for(int i=2; i<=n; ++i)
        for(int j=0; j<26; ++j)
            a[i][j]+=a[i-1][j];
    vector<int> res;
    for(auto &it:B){
        int l=it[0];
        int r=it[1];
        --l;
        int mx=0,cnt=0;
        for(int i=0; i<26; ++i){
            int freqency=a[r][i]-a[l][i];
            if(freqency>mx){
                mx=freqency;
                cnt=1;
            }
            else if(freqency==mx){
                ++cnt;
            }
        }
        res.push_back(cnt);
    }
    return res;
}


int32_t main(){
sp;
freopen("input2.txt","r",stdin);
freopen("output2.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        assert(s.size()>=1&&s.size()<=100000);
        int q,tempq;
        cin>>q>>tempq;
        assert(q>=1&&q<=50000);
        assert(tempq==2);
        vector<vector<int> > B(q,vector<int> (2));
        for(int i=0;i<q; ++i){
            cin>>B[i][0]>>B[i][1];
            assert(B[i][0]<=B[i][1]);
            assert(B[i][0]<=s.size()&&B[i][0]>=1);
            assert(B[i][1]>=1&&B[i][1]<=s.size());
        }
        vector<int> ans=solveit(s,B);
        for(auto &it:ans)
            cout<<it<<" ";
        cout<<"\n";
    }
    return 0;
}
