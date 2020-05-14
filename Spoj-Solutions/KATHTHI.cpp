/*
KATHTHI - KATHTHI
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define mxn 1001
#define inf 10000000
#define mp make_pair
#define gc getchar_unlocked
#define pc putchar_unlocked
int n,m;
char a[mxn][mxn];
int d[mxn][mxn];
int dir[][2]={{0,1},{1,0},{-1,0},{0,-1}};
bool check(int i,int j){
return (i>-1&&j>-1&&i<n&&j<m);
}

inline void read_in(int &x)
{
	register char c = gc();
	while(c<'0' || c>'9')
		c = gc();

	x=0;
	while(c>='0' && c<='9')
	{
		x = 10 * x + c - 48;
		c = gc();
	}

}
int main(){
int t;
read_in(t);
while(t--){
    read_in(n),read_in(m);
    for(int i=0; i<n; ++i){ for(int j=0; j<m; ++j) {
    	d[i][j]=inf;
    	a[i][j]=gc();
    }
    if(i!=n-1)
char ch=gc();
}
    d[0][0]=0;
    deque<pair<int,int> > q;
    q.push_front(mp(0,0));
    int x,y,dx,dy;
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop_front();
        for(int i=0; i<4; ++i){
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            if(check(dx,dy)){
                if(a[dx][dy]==a[x][y]){
                    if(d[dx][dy]>d[x][y]){
                        d[dx][dy]=d[x][y];
                        q.push_front(mp(dx,dy));
                    }
                }
                else{
                    if(d[dx][dy]>d[x][y]+1){
                        d[dx][dy]=d[x][y]+1;
                        q.push_back(mp(dx,dy));
                    }}}}}
   printf("%d\n",d[n-1][m-1]);
}
return 0;}
