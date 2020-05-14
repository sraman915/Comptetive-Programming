/*
http://www.spoj.com/problems/ABA12D/
SOLUTION BY RAMAN SHARMA
ABA12D - Sum of divisors!
*/

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 1000005

const int mx1=5000000;

int a[mxn],b[mxn],c[mx1];
void pre(){
for(int i=1; i<mxn; ++i)
    for(int j=i; j<mxn; j+=i)
        a[j]+=i;
for(int i=4; i<mx1; i+=2)c[i]=1;
for(int i=3; i*i<mx1; i+=2){
    if(!c[i])for(int j=i*i; j<mx1; j+=i+i)
        c[j]=1;
}
for(int i=2; i<mxn; ++i)
    if(!c[a[i]])b[i]=1+b[i-1];
    else b[i]=b[i-1];
}


int main(){
sp;
pre();
int t,x,y;
cin>>t;
while(t--){
    cin>>x>>y;
    cout<<b[y]-b[x-1]<<"\n";
}
return 0;}
