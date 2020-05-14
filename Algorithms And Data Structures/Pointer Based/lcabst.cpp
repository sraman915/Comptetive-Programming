#include<bits/stdc++.h>
using namespace std;
struct node{
int data;
node *left;
node *right;};

void create(int a,node *&root){
if(root==NULL)
    {
        node *newnode= new node;
        newnode->left=NULL;
        newnode->right=NULL;
        newnode->data=a;
        root=newnode;
    }
    else{
        if(root->data>a)
            create(a,root->left);
        else
            create(a,root->right);}
return;}

node *lca(node *root,int a,int b){
if(root==NULL) return NULL;
if(root->data>a&&root->data>b)
    return lca(root->left,a,b);
 if(root->data<a&&root->data<b)
return lca(root->right,a,b);
return root;
}

int main(){
node *root=NULL;
int n;
cin>>n;
while(n--){
    int x;
    cin>>x;
    create(x,root);
}
node *temp=lca(root,10,14);
cout<<temp->data;
return 0;}
