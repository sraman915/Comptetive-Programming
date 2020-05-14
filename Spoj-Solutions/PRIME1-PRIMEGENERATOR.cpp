/*
PRIME GENERATOR-PRIME1
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define mp make_pair
#define pi pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define inf 1000000000
#define mxn 100010


int main(){
    sp;
int t;
cin>>t;
while(t--){
    ll a,b;
    cin>>a>>b;
    vector<int> p(b-a+1,2);
    if(a==1)
        p[0]=1;

    for(ll i=2; i*i<=b; ++i){
        for(ll j=max(i*i,((a-1)/i+1)*i); j<=b; j+=i){
        if(j==i*i)
            p[j-a]+=1;
        else p[j-a]+=2;
                }
    }
    for(ll i=a; i<=b; ++i){
        if(p[i-a]==2)
            cout<<i<<"\n";
    }
    cout<<"\n";
}


return 0;}
