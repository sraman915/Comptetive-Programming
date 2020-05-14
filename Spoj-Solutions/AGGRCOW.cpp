/*
AGGRCOW - Aggressive cows
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

bool check(int *a,int c,int n,int m){
int x=1,y=a[0];
for(int i=1; i<n; ++i){
    if(a[i]-y>=m){
        ++x;
        y=a[i];
    }
    if(x==c) return true;
}
return false;
}


int main(){
sp;
int t;
cin>>t;
while(t--){
    int n,c;
    cin>>n>>c;
    int a[n];
    for(int i=0; i<n; ++i)cin>>a[i];
    sort(a,a+n);
    int l=0,r=a[n-1]-a[0];
    int ans;
    while(l<=r){
        int m=(l+r)>>1;
        if(check(a,c,n,m)){
            ans=m;
            l=m+1;
        }
        else r=m-1;
    }
    cout<<ans<<"\n";
}
return 0;}

