/*
BRCKTS - Brackets
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define mxn 30001
struct node{
int open,close;
node(){
open=0,close=0;
}
}tree[4*mxn];
string s;
node combine(node a,node b){
int x=min(a.open,b.close);
node c;
c.open=a.open+b.open-x;
c.close=a.close+b.close-x;
return c;
}
void build(int i,int l,int r){
if(l==r){
    if(s[l]==')'){
        tree[i].close=1;
        tree[i].open=0;
    }
    else{
        tree[i].open=1;
        tree[i].close=0;
    }
return;
}
int m=(l+r)/2;
build(i+i,l,m);
build(i+i+1,m+1,r);
tree[i]=combine(tree[i+i],tree[i+i+1]);
}
void update(int i,int l,int r,int pos){
if(l==r){
       if(s[l]==')'){
        tree[i].close=1;
        tree[i].open=0;
    }
    else{
        tree[i].open=1;
        tree[i].close=0;
    }
return;
}
int m=(l+r)/2;
if(pos>=l&&pos<=m)
    update(i+i,l,m,pos);
else
    update(i+i+1,m+1,r,pos);
tree[i]=combine(tree[i+i],tree[i+i+1]);
}
int main(){
for(int i=1; i<=10; ++i){
    printf("Test %d:\n",i);
    for(int j=0; j<4*mxn; ++j)
        tree[i]=node();
    int n,m;
    scanf("%d",&n);
    cin>>s;
    build(1,0,n-1);
    scanf("%d",&m);
    int x;
    while(m--){
        scanf("%d",&x);
        if(x){
            --x;
            if(s[x]==')')
                s[x]='(';
            else
                s[x]=')';
            update(1,0,n-1,x);
        }
        else{
            if(tree[1].close==0&&tree[1].open==0)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }



}
return 0;}
