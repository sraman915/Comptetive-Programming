/*
DQUERY - D-query
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int> > piii;
piii query[200001];
int c[1000001],a[30001],block;
int answ=0;

bool comp(piii a,piii b){
int x=a.first/block;
int y=b.first/block;
if(x!=y)
return x<y;
return a.second.first<b.second.first;
}

void add(int pos){
++c[a[pos]];
if(c[a[pos]]==1)
    ++answ;
}

void del(int pos){
--c[a[pos]];
if(c[a[pos]]==0)
    --answ;
}

int main(){
int n;
scanf("%d",&n);
block=ceil(sqrt(n));
for(int i=0; i<n; ++i) scanf("%d",a+i);
int q;
scanf("%d",&q);
int l,r;
for(int i=0; i<q; ++i){
    scanf("%d%d",&l,&r);
    piii p=make_pair(l-1,make_pair(r-1,i));
    query[i]=p;
}
sort(query,query+q,comp);
int ans[q];
int ml=0,mr=0;
for(int i=0; i<q; ++i){
    l=query[i].first;
r=query[i].second.first;
while(ml<l){
    del(ml);
    ++ml;
}
while(ml>l){
    add(ml-1);
    --ml;
}
while(mr<=r){
    add(mr);
    ++mr;
}
while(mr>r+1){
    del(mr-1);
    --mr;
}
ans[query[i].second.second]=answ;
}
for(int i=0; i<q; ++i)
    printf("%d\n",ans[i]);
return 0;}
