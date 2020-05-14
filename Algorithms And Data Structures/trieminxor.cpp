#include<bits/stdc++.h>
using namespace std;
struct trie{
int k;
trie *a[2];};

trie *getnode(){
trie *temp=new trie;
temp->k=0;
temp->a[0]=NULL;
temp->a[1]=NULL;
return temp;
}

void insertt(trie *temp,int val){
//trie *temp=root;
for(int i=31; i>=0; --i){
  bool curr=(val&(1<<i));
  if(!temp->a[curr])
    temp->a[curr]=getnode();
  temp=temp->a[curr];
}
temp->k=val;
}
int minxorq(trie *temp, int val){
//trie *temp=root;
for(int i=31; i>=0; --i){
    bool curr=(val&(1<<i));
    if(temp->a[curr])
        temp=temp->a[curr];
    else if(temp->a[1-curr])
        temp=temp->a[1-curr];
}
return (val^temp->k);
}
int mxor(int b[],int n){
trie *root=getnode();
int ans=100000000;
insertt(root,b[0]);
for(int i=1; i<n; ++i){
    ans=min(minxorq(root,b[i]),ans);
    insertt(root,b[i]);
}
return ans;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n=4;
int b[]={9,5,3,8};
cout<<mxor(b,n);
return 0;}
