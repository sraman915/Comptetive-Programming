/*
NFACTOR - N-Factorful
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define mxn 1000005
vector<int> a(mxn),g[11];

void pre(){
a[0]=0,a[1]=0;
for(int i=2; i<mxn; ++i){
        if(!a[i]){
    for(int j=i; j<mxn; j+=i){
        ++a[j];
    }
        }
}
for(int i=1; i<mxn; ++i){
    if(a[i]<11)
        g[a[i]].push_back(i);
}
}
int main(){
pre();
int t;
cin>>t;
while(t--){
    int n,a,b;
    cin>>a>>b>>n;
    if(n>7){
        cout<<"0\n";
        continue;
    }
    int x=upper_bound(g[n].begin(),g[n].end(),b)-g[n].begin();
    int y=lower_bound(g[n].begin(),g[n].end(),a)-g[n].begin();
    cout<<x-y<<"\n";

}

return 0;}
