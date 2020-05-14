#include<bits/stdc++.h>
using namespace std;


struct node{
int data;
node *next;
};

node *get(int x){
node *temp=new node;
temp->data=x;
temp->next=NULL;
return temp;
}

node *insert(node *root,int x){
node *temp=get(x);
if(root==NULL){
    root=temp;
    return root;
}
temp->next=root;
root=temp;
return root;
}

void print(node *root){
while(root){
    cout<<root->data<<" ";
    root=root->next;
}
cout<<"\n";
}

node *add(node *root1,node *root2){
if(root1==NULL)return root2;
if(root2==NULL)return root1;
node *root=NULL,*prev=NULL;
int c=0;
while(root1&&root2){
    int z=root1->data+root2->data+c;
    c=z/10;
    z=z%10;
   node *temp=get(z);
   root1=root1->next;
   root2=root2->next;
   if(prev==NULL){
    root=temp;
   prev=temp;
   }
   else{
   prev->next=temp;
   prev=temp;
   }
}
while(root1){
    int z=c+root1->data;
    c=z/10;
    z%=10;
    node *temp=get(z);
    prev->next=temp;
    prev=temp;
    root1=root1->next;
}

while(root2){
    int z=c+root2->data;
    c=z/10;
    z%=10;
    node *temp=get(z);
    prev->next=temp;
    prev=temp;
    root2=root2->next;
}
if(c)
    prev->next=get(c);
return root;
}


node *rev(node *root){
node *prev=NULL,*next=NULL,*curr=root;
while(curr){
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
}
root=prev;
return root;
}

int main(){
node *root1=NULL,*root2=NULL,*root=NULL;
int n,m,x;
cin>>n>>m;
cout<<"ENTER ELEMENTS IN THE FIRST LINKED LIST\n";
for(int i=1; i<=n;++i){
    cin>>x;
    root1=insert(root1,x);
}

cout<<"ENTER ELEMENTS IN THE FIRST LINKED LIST\n";
for(int i=1; i<=m;++i){
    cin>>x;
    root2=insert(root2,x);
}

//root1=rev(root1);
//root2=rev(root2);
print(root1);
print(root2);
root=add(root1,root2);
print(root);

return 0;}
