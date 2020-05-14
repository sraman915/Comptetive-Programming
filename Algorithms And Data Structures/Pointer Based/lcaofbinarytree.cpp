#include<bits/stdc++.h>
using namespace std;

struct node{
node *left,*right;
int data;
};

node *get(int x){
node *temp=new node;
temp->data=x;
temp->left=temp->right=NULL;
return temp;
}

node *getlca(node *root,int x,int y){
if(root==NULL)return NULL;
if(root->data==x||root->data==y)return root;
node *lcaleft=getlca(root->left,x,y);
node *lcaright=getlca(root->right,x,y);
if(lcaleft&&lcaright)return root;
if(lcaleft)return lcaleft;
return lcaright;
}

bool present(node *root,int x){
if(!root)return false;
if(root->data==x)return true;
return (present(root->left,x)|present(root->right,x));
}

int lca(node *root,int x,int y){
if(!present(root,x)||!present(root,y))return -1;
node *temp=getlca(root,x,y);
if(temp)return temp->data;
return -1;
}

void pre(node *root,int x,string &y,string &p){
if(!root)return;
if(root->data==x){
    if(y.empty())
        y=p;
    return;
}
p.push_back('0');
pre(root->left,x,y,p);
p.pop_back();
p.push_back('1');
pre(root->right,x,y,p);
p.pop_back();
}

int lcausingprefix(node *root,int x,int y){
string a,b;
string p="r";
pre(root,x,a,p);
if(a.empty())return -1;
p.clear();
p="r";
pre(root,y,b,p);
if(b.empty())return -1;
if(x==y)return x;
int n=min(a.size(),b.size());
int i=1;
if(n==1)return root->data;
while(i<n){
    if(a[i]!=b[i])return root->data;
    if(a[i]=='0')root=root->left;
    else root=root->right;
    ++i;
}
return root->data;
}

int main(){
node *root=get(8);
root->left=get(1);
root->right=get(6);
cout<<lcausingprefix(root,1,5);
cout<<lca(root,1,5);
}
