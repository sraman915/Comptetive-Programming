/*
FACEFRND - Friends of Friends
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int n;
cin>>n;
set<int> s;
vector<int> g[n];
int id,m,x;
for(int i=0; i<n; ++i){
    cin>>id;
    s.insert(id);
    cin>>m;
    for(int j=0; j<m; ++j){
        cin>>x;
        g[i].push_back(x);
    }
}
int ans=0;
for(int i=0; i<n; ++i){
    for(int j=0; j<g[i].size(); ++j){
        if(s.find(g[i][j])==s.end())
            ++ans;
            s.insert(g[i][j]);
    }
}
cout<<ans;

return 0;}
