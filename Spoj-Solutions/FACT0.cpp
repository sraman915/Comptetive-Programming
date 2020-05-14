/*
SOLUTION BY RAMAN SHARMA
FACT0 - Integer Factorization (15 digits)
https://www.spoj.com/problems/FACT0/
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
#define mxn 200005


int main(){
sp;
ll n;
while(1){
cin>>n;
if(!n)break;
int x=0;
    for(ll i=2; i*i<=n; ++i){
        if(n%i==0){
                if(x)cout<<" ";
            int y=0;
            while(n%i==0){
                n=n/i;
                ++y;
            }
        x=1;
        cout<<i<<"^"<<y;
        }

    }
    if(n>1){
            if(x)cout<<" ";
            cout<<n<<"^1";
    }
    cout<<"\n";
}
return 0;}
