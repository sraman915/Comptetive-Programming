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

vector<int> solveit(vector<int> &A,vector<int> &B){
    int n=A.size();
    int m=B.size();
    vector<int> ans(m);
    pair<int,int> b[m];
    for(int i=0; i<m; ++i){
        b[i].first=B[i];
        b[i].second=i;
    }
    sort(A.begin(),A.end());
    sort(b,b+m);
    int x=b[0].first+1;
    int j=0,i=0;
    while(i<m){
        while(j<n&&x>A[j])
            ++j;
        if(j<n&&x==A[j]){
            ++x;
            continue;
        }
        while(i<m&&x>b[i].first){
            ans[b[i].second]=x;
            ++i;
        }
        if(i<m)
            x=b[i].first+1;
    }
    return ans;
}

vector<int> anotherapproach(vector<int> &A,vector<int> &B){
    int n=A.size();
    int q=B.size();
    sort(A.begin(),A.end());
    map<int,int> mp;
    for(int i=0;i<n;){
        int j=i;
        for(;j<n-1;j++)
            if(A[j]<A[j+1]-1)
                break;
        for(int k=i;k<=j;k++)
            mp[A[k]]=A[j];
        i=j+1;
    }
    vector<int> ans;
    for(auto &x:B){
        if(mp[x]==0){
            if(mp[x+1]==0)
                ans.push_back(x+1);
            else
                ans.push_back(mp[x+1]+1);
        }
        else
            ans.push_back(mp[x]+1);
    }
    return ans;
}

int32_t main(){
sp;
//freopen("input3.txt","r",stdin);
//freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    assert(n>=1&&n<=100000);
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin>>a[i];
        assert(a[i]>=1&&a[i]<=1000000000);
    }
    int q;
    cin>>q;
    assert(q>=1&&q<=100000);
    vector<int> b(q);
    for(int i=0; i<q; ++i){
        cin>>b[i];
        assert(b[i]>=1&&b[i]<=1000000000);
    }
    vector<int> ans=solveit(a,b);
    for(auto &it:ans)
        cout<<it<<" ";
    cout<<"\n";
}
return 0;}
