/*
TIPTOP-TIPTOP
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int t;
cin>>t;
while(t--){
ll n;
cin>>n;
ll p=sqrt(n);
if(p*p==n)
    cout<<"Yes\n";
else
    cout<<"No\n";
}
return 0;
}
