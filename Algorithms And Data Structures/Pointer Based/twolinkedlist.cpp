#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cerr<<x<<"\n"
#define debug2(x,y) cerr<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<"\n"
#define nl cerr<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cerr<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005


struct node{
int data;
node *next;
node(){
next=NULL;
}
node(int y){
data=y;
next=NULL;
}
};

node *head1,*head2;

node *insertb(node *head,int x){
node *temp=new node();
temp->data=x;
if(head==NULL)head=temp;
else{
    temp->next=head;
    head=temp;
}
return head;
}

node *insertl(node *head,int x){
node *temp=new node();
temp->data=x;
if(head==NULL)head=temp;
else{
    node *t=head;
    while(t->next!=NULL)t=t->next;
    t->next=temp;
}
return head;
}

void display(node *head){
node *t=head;
if(head==NULL){
    cout<<"NULL\n";
    return;
}
while(t){
    cout<<t->data<<" ";
    t=t->next;
}
cout<<"\n";
}

node *deletelist(node *head){
node *temp=head;
while(temp){
    node *next=temp->next;
    delete(temp);
    temp=next;
}
head=NULL;
return head;
}

node *mergelinkedlist(node *head1,node *head2){
if(head1==NULL)return head2;
if(head2==NULL)return head1;
node *head=NULL,*curr1=head1,*curr2=head2,*curr;
if(curr1->data<curr2->data){
    head=curr1;
    curr1=curr1->next;
}
else{
    head=curr2;
    curr2=curr2->next;
}
curr=head;
while(curr1&&curr2){
    if(curr1->data<curr2->data){
        curr->next=curr1;
        curr1=curr1->next;
        curr=curr->next;
    }
    else{
        curr->next=curr2;
        curr2=curr2->next;
        curr=curr->next;
    }
}

if(curr1)curr->next=curr1;
if(curr2)curr->next=curr2;
return head;
}

node *mergesortonlinkedlist(node *head){
if(head==NULL||head->next==NULL)return head;
node *p1=head,*p2=head->next;
while(p2&&p2->next){
    p1=p1->next;
    p2=p2->next->next;
}
p2=p1->next;
p1->next=NULL;
node *temp1=mergesortonlinkedlist(head);
node *temp2=mergesortonlinkedlist(p2);
return mergelinkedlist(temp1,temp2);
}

node *addtwonumberinlinkedlist(node *head1,node *head2){
if(head1==NULL)return head2;
if(head2==NULL)return head1;
node *curr1=head1,*curr2=head2,*head=NULL,*prev=NULL,*temp;
int c=0;
while(curr1&&curr2){
    int y=curr1->data+curr2->data+c;
    temp=new node(y%10);
    c=y/10;
    if(head==NULL){
        head=temp;
        prev=temp;
    }
    else{
        prev->next=temp;
        prev=temp;
    }
    curr1=curr1->next;
    curr2=curr2->next;
}
while(curr1){
    int y=curr1->data+c;
    temp=new node(y%10);
    c=y/10;
    prev->next=temp;
    prev=temp;
    curr1=curr1->next;
}

while(curr2){
    int y=curr2->data+c;
    temp=new node(y%10);
    c=y/10;
    prev->next=temp;
    prev=temp;
    curr2=curr2->next;
}
return head;
}


int main(){
//sp;
head1=NULL,head2=NULL;
node *head3=NULL;

while(1){
  int c;
  cin>>c;
  if(c==1){
    int x;
    cin>>x;
    head1=insertb(head1,x);
  }
  else if(c==2){
        int x;
  cin>>x;
    head2=insertb(head2,x);
  }
  else if(c==3){
    display(head1);
    display(head2);
    display(head3);
  }
  else if(c==4)head1=deletelist(head1);
  else if(c==5)head2=deletelist(head2);
  else if(c==6)head3=deletelist(head3);
  else if(c==7){
        head1=mergesortonlinkedlist(head1);
        head2=mergesortonlinkedlist(head2);
        head3=mergelinkedlist(head1,head2);
  }
  else if(c==8)head3=addtwonumberinlinkedlist(head1,head2);
  else break;
}
return 0;}
