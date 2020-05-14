/*
NAKANJ - Minimum Knight moves !!!
SOLUTION BY RAMAN SHARMAA
*/
#include<bits/stdc++.h>
using namespace std;
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define inf 10000000
#define mp make_pair
int b[9][9],vis[9][9];
int dir[][2]={{-2,1},{-2,-1},{-1,-2},{1,-2},{1,2},{-1,2},{2,1},{2,-1}};

bool check(int x,int y){
return (x>0&&y>0&&x<9&&y<9);
}

void bfs(int x,int y){
for(int i=0; i<9; ++i) for(int j=0; j<9; ++j) vis[i][j]=inf;
vis[x][y]=0;
queue<pair<int,int> > q;
q.push(mp(x,y));
while(!q.empty()){
    x=q.front().first;
    y=q.front().second;
    q.pop();
    int dx,dy;
    for(int i=0; i<8; ++i){
        dx=x+dir[i][0];
        dy=y+dir[i][1];
        if(check(dx,dy)&&vis[dx][dy]>vis[x][y]+1){
            vis[dx][dy]=vis[x][y]+1;
            q.push(mp(dx,dy));
        }
    }
}
}
int main(){
    sp;
    int t;
    cin>>t;
    while(t--){
        int x1,y1,x2,y2;
        string s,s1;
        cin>>s>>s1;
        x1=s[0]-'a'+1;
        y1=s[1]-'0';
        x2=s1[0]-'a'+1;
        y2=s1[1]-'0';
        bfs(x1,y1);
        cout<<vis[x2][y2]<<"\n";

    }

return 0;}
