#include<bits//stdc++.h>
using namespace std;
#define n 8
int board[8][8];

int moves[][2] = { {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1},{ -1, -2}, {1, -2},{2, -1}};
bool safe(int x,int y){
return (x>=0&&x<n&&y>=0&&y<n&&board[x][y]==-1);
}
void print(){
for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
        cout<<board[i][j]<<" ";}
    cout<<endl;}
}
bool solve(int x,int y,int pos){
if(pos==n*n)
    return true;
    int nextx,nexty;
    for(int i=0; i<8; ++i){
         nextx=x+moves[i][0];
         nexty=y+moves[i][1];
        if(safe(nextx,nexty)) {
            board[nextx][nexty]=pos;
            if(solve(nextx,nexty,pos+1)==true)
            return true;
            else
                board[nextx][nexty]=-1;
}}
return false;}
int main(){
memset(board,-1,sizeof(board));
board[0][0]=0;
if(solve(0,0,1))
    print();
else
    cout<<"Not possible\n";
return 0;
}
