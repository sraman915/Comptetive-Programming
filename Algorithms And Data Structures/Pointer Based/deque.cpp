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
node *prev,*next;
node(){
prev=NULL;
next=NULL;
}
};

node *head,*lastp;

void insertfront(int x){
node *temp=new node();
temp->data=x;
temp->prev=NULL;
temp->next=head;
if(head!=NULL)
    head->prev=temp;
if(lastp==NULL)lastp=temp;
head=temp;
}

void insertback(int x){
node *temp=new node();
temp->data=x;
temp->prev=lastp;
temp->next=NULL;
if(lastp!=NULL)
    lastp->next=temp;
if(head==NULL)head=temp;
lastp=temp;
}

int elementatback(){
if(lastp==NULL)return -1;
return lastp->data;
}

int elementatfront(){
if(head==NULL)return -1;
return head->data;
}

void deleteatfront(){
if(head==NULL)return;
node *temp=head->next;
temp->prev=NULL;
delete(head);
head=temp;
if(head==NULL)lastp=NULL;
}

void deleteatback(){
if(lastp==NULL)return;
node *temp=lastp->prev;
if(lastp->prev==NULL){
    free(lastp);
    lastp=NULL;
    head=NULL;
    return;
}
temp->next=NULL;
delete(lastp);
lastp=temp;
if(lastp==NULL)head=NULL;
}


void display(){
node *temp=head;
while(head){
    cout<<head->data<<" ";
    head=head->next;
}
head=temp;
cout<<"\n";
}



int main(){
//sp;
head=NULL;
lastp=NULL;
while(1){
    int c,x;
    cin>>c;
    if(c==1){
            cin>>x;
        cout<<"INSERTING AT THE FRONT\n";
    insertfront(x);
    }
    else if(c==2){
        cin>>x;
        cout<<"INSERTING AT THE BACK\n";
    insertback(x);
    }
    else if(c==3)
        cout<<"ELEMENT AT THE BACK\t"<<elementatback()<<"\n";
    else if(c==4)
        cout<<"ELEMENT AT THE FRONT\t"<<elementatfront()<<"\n";
    else if(c==5)display();
    else if(c==6){
        cout<<"DELETING AT THE FRONT\n";
        deleteatfront();
    }
    else if(c==7){
        cout<<"DELETING AT THE BACK\n";
        deleteatback();
    }
    else break;
}
return 0;}
