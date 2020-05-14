#include<bits/stdc++.h>
using namespace std;
struct node{
int data;
node *left,*right;
};

node *create(int d){
node *temp=new node;
temp->left=NULL;
temp->right=NULL;
temp->data=d;
return temp;
}

node *insert(node *root,int d){
if(root==NULL) return create(d);
if(d<=root->data)
    root->left=insert(root->left,d);
else if(d>root->data)
    root->right=insert(root->right,d);
return root;
}

node* findmin(node* root){
	while(root->left != NULL) root = root->left;
	return root;
}

node *del(node *root,int d){
if(root==NULL) return root;
if(root->data>d) root->left=del(root->left,d);
else if(root->data<d) root->right=del(root->right,d);
else{
if(root->left==NULL&&root->right==NULL){
    delete root;
    root=NULL;
}
else if(root->left==NULL){
node *temp=root;
root=root->right;
delete(temp);
}
else if(root->right==NULL){
    node *temp=root;
    root=root->left;
    delete(temp);
}
else{
    node *temp=findmin(root->right);
    root->data=temp->data;
    root->right=del(root->right,temp->data);
}
}
return root;
}
void inorder(node *root){
if(root==NULL) return;
inorder(root->left);
cout<<root->data<<" ";
inorder(root->right);
}
int main(){
int n,x;
node *root=NULL;
cin>>n;
for(int i=0; i<n; ++i){
    cin>>x;
    root=insert(root,x);
}
inorder(root);

root=del(root,10);
cout<<"\n";
inorder(root);
}
