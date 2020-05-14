/*
https://www.spoj.com/problems/MDOLLS/
MDOLLS - Nested Dolls
SOUTION BY RAMAN SHARMA

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

pi p[20003];
vector<pi> ans;

bool cmp(const pi& a, const pi& b){
    if(a.f == b.f)
        return a.s > b.s;
        return a.f < b.f;
}

int main(){
sp;
int t,n,u,v;
cin>>t;
while(t--){
cin>>n;
for(int i=0; i<n; ++i){
cin>>u>>v;
p[i]=make_pair(u,v);
}
sort(p,p+n,cmp);
ans.clear();
ans.pb(p[n-1]);
for(int i=n-2; i>-1; --i){
    int l=0,r=(int)ans.size()-1,m;
    while(l<=r){
        m=(l+r)>>1;
        if(ans[m].s<=p[i].s)l=m+1;
        else r=m-1;
    }
    if(l==ans.size())
        ans.pb(p[i]);
    else
        ans[l]=p[i];
}
cout<<ans.size()<<"\n";
}
return 0;}
