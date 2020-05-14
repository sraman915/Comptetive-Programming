/*
DCEPCA03 - Totient Extreme
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define mxn 10001
ll a[mxn],b[mxn];
void pre(){
for(ll i=0; i<mxn; ++i) a[i]=i;
for(ll i=2; i<mxn; ++i){
    if(a[i]==i){
        for(ll j=i; j<mxn; j+=i){
            a[j]/=i;
            a[j]*=(i-1);
        }
    }
}
for(ll i=1; i<mxn; ++i){
    a[i]+=a[i-1];
b[i]=a[i]*a[i];
}
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
pre();
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    cout<<b[n]<<"\n";
}
return 0;}
