/*
GERGOVIA - Wine trading in Gergovia
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long
int main(){
sp;
int n;
cin>>n;
while(n){
ll ans=0,psum=0,x;
for(int i=0; i<n; ++i)
    cin>>x,psum+=x,ans+=abs(psum);
cout<<ans<<"\n";
cin>>n;
}
return 0;}

