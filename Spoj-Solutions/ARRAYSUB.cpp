/*
ARRAYSUB - subarrays
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mp make_pair
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define priority_queue pq
#define inf (ll)1e15
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005


int main(){
sp;
int n,k;
cin>>n;
int a[n];
for(int i=0; i<n; ++i)cin>>a[i];
cin>>k;
vector<int> v;
deque<int> q;
for(int i=0; i<k; ++i){
    while(!q.empty()&&a[q.back()]<=a[i])
        q.pop_back();
    q.pb(i);
}
for(int i=k; i<n; ++i){
        v.pb(a[q.front()]);
    while(!q.empty()&&q.front()<=i-k)
        q.pop_front();
    while(!q.empty()&&a[q.back()]<=a[i])
    q.pop_back();
    q.pb(i);
}
v.pb(a[q.front()]);
for(int i:v) cout<<i<<" ";
return 0;}

