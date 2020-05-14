/*
CEQU - Crucial Equation
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
for(int i=1; i<=t; ++i){
    int a,b,c;
    cin>>a>>b>>c;
    int x=__gcd(a,b);
cout<<"Case "<<i<<": ";
    if(c%x)
        cout<<"No\n";
    else
        cout<<"Yes\n";
}
return 0;}
