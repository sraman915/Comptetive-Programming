/*
KFSTB-HELP THE COMMANDER IN CHIEF
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
vector<int>graph[20000],check(20000),ways(20000,0),topsort(20000);
int count1;
void dfs(int a){
int i;
check[a]=1;
for(i=0;i<graph[a].size();i++){
    int y=graph[a][i];
    if(check[y]==0)
        dfs(y);
}

topsort[count1--]=a;
}
int main(){
int tt;
cin>>tt;
while(tt--){
    int i;
    for(i=0;i<20000;i++){
        graph[i].clear();
        check[i]=0;
        ways[i]=0;
    }
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    for(i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        graph[u].push_back(v);
    }
    count1=n;
    ways[t]=1;
    //cout<<t<<" "<<ways[t]<<endl;
    dfs(s);
    int y;
    for(i=n;i>0;i--){
        y=topsort[i];
        //cout<<y<<" ";
        for(int j=0;j<graph[y].size();j++){
            int k=graph[y][j];
            if(y!=t){
                ways[y]=(ways[y]%mod+ways[k]%mod)%mod;
                   //cout<<y<<" "<<k<<" "<<endl;
            }
        }
    }
for(int i=n; i>0; --i)
    cout<<topsort[i]<<" ";
cout<<endl;
    printf("%d\n",ways[s]);
}
}
