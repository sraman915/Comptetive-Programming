#include<bits/stdc++.h>
using namespace std;
struct node{
int d,h;
node *left,*right;
};

node *create(int data){
node *temp=new node;
temp->d=data;
temp->left=NULL;
temp->right=NULL;
temp->h=1;
return temp;
}
int height(node *root){
if(root==NULL)
    return 0;
    return root->h;
}
int balance(node *root){
if(root==NULL)
    return 0;
return height(root->left)-height(root->right);
}

node *rightr(node *temp){
node *x,*y;
x=temp->left;
y=x->right;
temp->left=y;
x->right=temp;

temp->h=max(height(temp->left),height(temp->right))+1;
x->h=max(height(x->left),height(x->right))+1;
return x;
}

node *leftr(node *temp){
node *x,*y;
x=temp->right;
y=x->left;
temp->right=y;
x->left=temp;

temp->h=max(height(temp->left),height(temp->right))+1;
x->h=max(height(x->left),height(x->right))+1;
return x;
}

node *insert(node *root,int k){
    if(root==NULL)
        return create(k);
if(root->d>k)
    root->left=insert(root->left,k);
else if(root->d<k)
    root->right=insert(root->right,k);
else return root;
root->h=1+max(height(root->left),height(root->right));
int bal=balance(root);
if(bal>1&&k<root->left->d)
    return rightr(root);
if(bal<-1&&k>root->right->d)
    return leftr(root);
if(bal>1&&k>root->left->d){
    root->left=leftr(root->left);
    return rightr(root);
}
if(bal<-1&&k<root->right->d){
    root->right=rightr(root->right);
    return leftr(root);
}
return root;
}

void preorder(node *root){
if(!root) return;
cout<<root->d<<" "<<balance(root)<<"\n";
preorder(root->left);
preorder(root->right);
}
int main(){
int n,x;
cin>>n;
node *root=NULL;
while(n--){
    cin>>x;
    root=insert(root,x);
}
cout<<"\n";

preorder(root);
return 0;}
