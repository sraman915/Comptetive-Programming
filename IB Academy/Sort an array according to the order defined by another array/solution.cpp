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


vector<int> solveit(vector<int> &a,vector<int> &b){
    unordered_map<int,int> mp;
    vector<pair<int,int> > notInB;
    unordered_map<int,int>::iterator it1;
    for(auto &it:a)
        ++mp[it];
    vector<int> ans;
    for(auto &it:b){
        it1=mp.find(it);
        if(it1!=mp.end()){
            int y=mp[it];
            while(y--)
                ans.push_back(it);
            mp.erase(it1);
        }
    }
    for(auto &it:mp)
        notInB.push_back({it.first,it.second});
    sort(notInB.begin(),notInB.end());
    for(auto &it:notInB){
        int x=it.first;
        int y=it.second;
        while(y--)
            ans.push_back(x);
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
    int n1,n2;
    cin>>n1;
    assert(n1>=1&&n1<=100000);
    vector<int> a(n1);
    for(int i=0; i<n1; ++i){
        cin>>a[i];
        assert(a[i]>=0&&a[i]<=1000000000);
    }
    cin>>n2;
    assert(n2>=1&&n2<=100000);
    vector<int> b(n2);
    for(int i=0; i<n2; ++i){
        cin>>b[i];
        assert(b[i]>=0&&b[i]<=1000000000);
    }
    vector<int> ans=solveit(a,b);
    assert(ans.size()==n1);
    for(auto &it:ans)
        cout<<it<<" ";
    cout<<"\n";
}
return 0;}
