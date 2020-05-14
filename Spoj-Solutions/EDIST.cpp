/*
EDIST - Edit distance
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
string a,b;
cin>>a>>b;
int n=a.size(),m=b.size();
int x[n+1][m+1];
memset(x,0,sizeof(x));
for(int i=0; i<=n; ++i)
    x[i][0]=i;
for(int i=0; i<=m; ++i)
        x[0][i]=i;
for(int i=1; i<=n; ++i){
    for(int j=1; j<=m; ++j){
        if(a[i-1]==b[j-1])
            x[i][j]=x[i-1][j-1];
         else
            x[i][j]=1+min(x[i-1][j],min(x[i][j-1],x[i-1][j-1]));
    }
}
cout<<x[n][m]<<"\n";
}
return 0;}
