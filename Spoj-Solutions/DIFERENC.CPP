/*

SOLUTION BY RAMAN SHARMA
https://www.spoj.com/problems/DIFERENC/
DIFERENC - DIFERENCIJA
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
#define mxn 400005

ll l1[mxn],l2[mxn],r1[mxn],r2[mxn];
ll a[mxn];

void free(stack<int> &s){
while(!s.empty())s.pop();
}

int main(){
sp;
int n;
cin>>n;
for(int i=0; i<n; ++i)cin>>a[i];
for(int i=0; i<n; ++i){
    l1[i]=l2[i]=-1;
    r1[i]=r2[i]=n;
}
stack<int> s;
for(int i=0; i<n; ++i){
    while(!s.empty()&&a[s.top()]<a[i])s.pop();
    if(!s.empty())l1[i]=s.top();
    s.push(i);
}
free(s);
for(int i=n-1; i>=0; --i){
    while(!s.empty()&&a[s.top()]<=a[i])s.pop();
    if(!s.empty())r1[i]=s.top();
    s.push(i);
}
free(s);
for(int i=0; i<n; ++i){
    while(!s.empty()&&a[s.top()]>a[i])s.pop();
    if(!s.empty())l2[i]=s.top();
    s.push(i);
}
free(s);
for(int i=n-1; i>=0; --i){
    while(!s.empty()&&a[s.top()]>=a[i])s.pop();
    if(!s.empty())r2[i]=s.top();
    s.push(i);
}

ll ans=0;
for(int i=0; i<n; ++i){
        ll x1=i-l1[i]-1;
        ll x2=r1[i]-i-1;
        ll p1=1LL*x1*x2+x1+x2+1;
        x1=i-l2[i]-1;
        x2=r2[i]-i-1;
        ll p2=1LL*x1*x2+x1+x2+1;
        ll p3=1LL*(p1-p2)*a[i];
        ans+=p3;
}
cout<<ans;
return 0;}
