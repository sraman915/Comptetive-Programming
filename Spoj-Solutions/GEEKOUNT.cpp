/*
GEEKOUNT - EVEN COUNT
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll p[11];
ll ans(ll n){
ll x=n;
ll c=0;
ll d[12];
ll i=0;
while((x/10)>0){
    d[i++]=x%10;
  c+=p[i];
  x/=10;
}
d[i]=x%10;
int y=1;
while(i>0){
    if(d[i]&1){
       c+=(d[i]/2)*p[i];
       y=1;
    }
    else{
        c+=(d[i]/2)*p[i];
        y=0;
        break;
    }
    --i;
}
if(y)
    c+=(d[i]+1)/2;
return n-c;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int t;
cin>>t;
p[0]=1;
p[1]=5LL;
for(int i=2; i<11; ++i)
    p[i]=5LL*p[i-1];
while(t--){
ll l,r;
cin>>l>>r;
    cout<<ans(r)-ans(l-1)<<"\n";
}


return 0;
}
