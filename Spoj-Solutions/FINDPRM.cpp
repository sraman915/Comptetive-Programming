/*
FINDPRM - Finding Primes
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
#define mxn 10000001
vector<int> a(mxn,1);
void sieve(){
a[0]=a[1]=0;
for(int i=4; i<mxn; i+=2)a[i]=0;
for(int i=3; i*i<=mxn; i+=2)
    if(a[i])for(int j=i*i; j<mxn; j+=2*i)
    a[j]=0;
for(int i=3; i<mxn; ++i)
    a[i]+=a[i-1];
}

int main(){
sp;
sieve();
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    cout<<a[n]-a[n>>1]<<"\n";
}
return 0;}

