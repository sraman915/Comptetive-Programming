/*
SHAKTI - SHAKTIMAN AND KILWISH
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007;
#define inf 1000000000000000
#define pb push_back
#define fr(i,s,e) for(i=s; i<e; ++i)
#define rf(i,s,e) for(i=s; i>=e; --i)


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int t,i,n;
cin>>t;
fr(i,0,t){
cin>>n;
if(n&1)
    cout<<"Sorry Shaktiman\n";
    else
    cout<<"Thankyou Shaktiman\n";
}

return 0;}
