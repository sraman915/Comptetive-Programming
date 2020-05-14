#include<bits/stdc++.h>
using namespace std;

struct node{
int data;
node *next,*prev;
node(){
data=0;
next=prev=NULL;
}

node(int newdata){
data=newdata;
next=prev=NULL;
}
};

class dll{
node *head,*lastp;
public:
    int dllsize;
     dll(){
    head=lastp=NULL;
    dllsize=0;
    }
    void display();
    void insertbeg(int x);
    void deletelast();
    node *beginpointer();
    void deletebypointer(node *del);
    int lastelement();
};


void dll::display(){
node *temp=head;
while(temp){
    cout<<temp->data<<" ";
    temp=temp->next;
}
cout<<"\n";
}

void dll::insertbeg(int x){
node *temp=new node(x);
if(head==NULL){
    head=temp;
    lastp=temp;
}
else{
    head->prev=temp;
    temp->next=head;
    head=temp;
}
++dllsize;
}

void dll::deletelast(){
if(head==NULL)return;
node *temp=lastp;
delete(temp);
lastp=lastp->prev;
if(lastp)
lastp->next=NULL;
if(lastp==NULL)
    head=NULL;
--dllsize;
}

int dll::lastelement(){
if(lastp==NULL)return -1;
return lastp->data;
}

node *dll::beginpointer(){
return head;
}

void dll::deletebypointer(node *del){
if(del==head){
    node *temp=head;
    head=temp->next;
    if(head==NULL)lastp=NULL;
    delete(temp);
    --dllsize;
    return;
}
if(del==lastp){
    node *temp=lastp;
    lastp=lastp->prev;
    delete(temp);
    if(lastp==NULL)head=NULL;
    else lastp->next=NULL;
    --dllsize;
    return;

}

node *temp=head;
while(temp){
    if(temp==del){
        node *prev=temp->prev;
        node *next=temp->next;
        prev->next=next;
        next->prev=prev;
        delete(temp);
        --dllsize;
        return;
    }
    temp=temp->next;
}
}



class lru{
public:
    unordered_map<int,node*> mp;
    dll ad;
    int csize;
    lru(){
    csize=0;
    ad=dll();
    }
    lru(int n){
    csize=n;
    }
    void insertprocess(int x);
    void display();
};

void lru::insertprocess(int x){
if(mp.find(x)==mp.end()){
    if(ad.dllsize==csize){
        int back_element=ad.lastelement();
        mp.erase(back_element);
        ad.deletelast();
        //ad.erase(mp[back_element]);
        ad.insertbeg(x);
        mp[x]=ad.beginpointer();
    }
    else{
        ad.insertbeg(x);
        mp[x]=ad.beginpointer();
    }
}
else{
        ad.deletebypointer(mp[x]);
        ad.insertbeg(x);
        mp[x]=ad.beginpointer();
}
}

void lru::display(){
ad.display();
}



int main(){
int n;
cin>>n;
lru a=lru(n);
while(1){
    int x;
    cin>>x;
    a.insertprocess(x);
    a.display();
}
return 0;}
