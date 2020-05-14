/*
MATGAME - Matrix Game
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int t;
cin>>t;
while(t--){
    int n,m,i,j,x=0;
    cin>>n>>m;
    int a[n][m];
   for(i=0; i<n; ++i) for(int j=0; j<m; ++j) cin>>a[i][j];
   for(i=0; i<n; ++i){
    for(j=m-2; j>=0; --j){
        if(a[i][j]<a[i][j+1]+1)
            a[i][j]-=1;
    }
   }
   for(i=0; i<n; ++i) x^=a[i][0];

    if(x)
        cout<<"FIRST\n";
    else
        cout<<"SECOND\n";
}

return 0;}
