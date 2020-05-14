#include<bits/stdc++.h>
using namespace std;

struct node{
int ch;
node *left,*right;
};
node *root;
queue<node*> q;

node *create(int c){
node *temp=new node;
temp->ch=c;
temp->left=NULL;
temp->right=NULL;
return temp;
}

void insert(int ch){
node *temp=create(ch);
if(root==NULL)
    root=temp;
else{
        node *top=q.front();
if(top->left==NULL)
    top->left=temp;
else if(top->right==NULL)
    top->right=temp;
if(top->left&&top->right)
    q.pop();
}
q.push(temp);
}

void preorder(node *root){
    if(root==NULL)
        return ;
        printf("%d ",root->ch);
        preorder(root->left);
        preorder(root->right);
}

void ipreorder(node *root){
if(!root) return;
stack<node*> s;
node *temp;
s.push(root);
while(!s.empty()){
    temp=s.top();
    s.pop();
    printf("%d ",temp->ch);
    if(temp->right)
        s.push(temp->right);
    if(temp->left)
            s.push(temp->left);
}
}

void inorder( node *root){
    if(root==NULL)
        return ;
        inorder(root->left);
        printf("%d ",root->ch);
        inorder(root->right);
}

void iinorder(node *root){
stack<node*> s;
if(!root) return ;
while(root){
        s.push(root);
root=root->left;
}
node *temp;
while(!s.empty()){
    temp=s.top();
    s.pop();
    cout<<temp->ch<<" ";
    if(temp->right){
        temp=temp->right;
    while(temp){
        s.push(temp);
        temp=temp->left;
    }
}}
}

void iiordermodify(node *root){
if(!root)return;
stack<node *> s;
s.push(root);
node *temp;
while(!s.empty()){
    temp=s.top();
    if(temp->left){
        s.push(temp->left);
        temp->left=NULL;
    }
    else{
        cout<<temp->ch<<" ";
        s.pop();
        if(temp->right)
            s.push(temp->right);
    }
}
}

void postorder(node *root){
    if(root==NULL)
        return ;
       postorder(root->left);
        postorder(root->right);
         printf("%d ",root->ch);
}

void ipostorder(node *root){
stack<node*> s1,s2;
if(!root) return;
s1.push(root);
node *temp;
while(!s1.empty()){
    temp=s1.top();
    s1.pop();
    s2.push(temp);
    if(temp->left)
        s1.push(temp->left);
    if(temp->right)
        s1.push(temp->right);
}
while(!s2.empty()){
    cout<<s2.top()->ch<<" ";
    s2.pop();
}
}

int height(node *root){
if(root==NULL)
    return 0;
return(max(height(root->left),height(root->right))+1);
}

void printlevel(node *root,int h){
if(root==NULL)
    return;
if(h==1)
    printf("%d ",root->ch);
else if(h>1){
    printlevel(root->left,h-1);
    printlevel(root->right,h-1);
}
}

void lvorder(node *root){
int h=height(root);
for(int i=1; i<=h; ++i)
    printlevel(root,i);
}

void nonreclevorder(node *root){
queue<node*> p;
p.push(root);
node *temp;
while(!p.empty()){
        temp=p.front();
    printf("%d ",temp->ch);
    if(temp->left)
        p.push(temp->left);
    if(temp->right)
        p.push(temp->right);
    p.pop();
}
}

void revlevorder(node *root){
int h=height(root);
for(int i=h; i>0; --i){
    printlevel(root,i);
}
}

void recprintlvorder(node *root,int h,int y){
if(root==NULL)
    return;
if(h==1)
    cout<<root->ch<<" ";
else{
    if(y){
        recprintlvorder(root->left,h-1,y);
        recprintlvorder(root->right,h-1,y);
    }
    else{
            recprintlvorder(root->right,h-1,y);
        recprintlvorder(root->left,h-1,y);
    }
}
}

void rsporder(node *root){
int h=height(root);
int y=0;
for(int i=1; i<=h; ++i){
    recprintlvorder(root,i,y);
    y^=1;
}
}
void rlvorderqueue(node *root){
queue<node*> p;
stack<node*> s;
if(!root)return;
p.push(root);
node *temp;
while(!p.empty()){
    temp=p.front();
    p.pop();
    s.push(temp);
    if(temp->right)
        p.push(temp->right);
    if(temp->left)
        p.push(temp->left);
}
while(!s.empty()){
    cout<<s.top()->ch<<" ";
    s.pop();
}
}

void isporder(node *root){
stack<node *> s1,s2;
node *temp;
if(root)
    s1.push(root);
    int y=0;
while(!s1.empty()||!s2.empty()){
    if(!y){
        y=1;
        while(!s1.empty()){
           temp=s1.top();
           cout<<temp->ch<<" ";
           s1.pop();
           if(temp->right)
            s2.push(temp->right);
           if(temp->left)
            s2.push(temp->left);
        }}
     else{
        y=0;
        while(!s2.empty()){
            temp=s2.top();
            cout<<temp->ch<<" ";
            s2.pop();
            if(temp->left)
                s1.push(temp->left);
            if(temp->right)
                s1.push(temp->right);
        }
     }
}
}

void revspiralorder(node *root){
queue<node*> qu;
stack<node*> s;
if(root){
    qu.push(root);
    s.push(root);
}
node *temp;
while(!qu.empty()){
    temp=qu.front();
    qu.pop();
    if(temp->left){
        qu.push(temp->left);
        s.push(temp->left);
    }
    if(temp->right){
        qu.push(temp->right);
        s.push(temp->right);
    }
}
while(!s.empty()){
    cout<<s.top()->ch<<" ";
    s.pop();
}
}

void invert(node *root){
  node *temp,*temp1;
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        temp=q.front();
        q.pop();
        temp1=temp->left;
        temp->left=temp->right;
        temp->right=temp1;
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);
    }
}

int main(){
int n;
root=NULL;
cout<<"Enter number of nodes\n";
cin>>n;
cout<<"Enter n node data\n";
int a;
for(int i=0; i<n; ++i){
    cin>>a;
    insert(a);
}
cout<<"\nRecursive preorder ";
preorder(root);
cout<<"\nNon-Recursive preorder ";
ipreorder(root);
cout<<"\n\nRecursive inorder ";
inorder(root);
cout<<"\nNon-Recursive inorder ";
iinorder(root);
cout<<"\n\nRecursive postorder ";
postorder(root);
cout<<"\nNon-Recursive postorder ";
ipostorder(root);
cout<<"\n\nRecursive levelorder ";
lvorder(root);
cout<<"\nNon-Recursive levelorder ";
nonreclevorder(root);
cout<<"\n\nrecursive Reverse level order ";
revlevorder(root);
cout<<"\nReverse level order ";
rlvorderqueue(root);
cout<<"\n\nNon-Recursive spiral order ";
isporder(root);
cout<<"\nRecursive spiral order ";
rsporder(root);
cout<<"\n\nNon-Recursive reverse spiral order ";
revspiralorder(root);
cout<<"\n";
cout<<"\n\nIterative Inorder Modification of tree ";
iiordermodify(root);
return 0;
}
