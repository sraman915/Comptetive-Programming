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
};

node *head;

void insertb(int x){
node *temp=new node();
temp->data=x;
if(head==NULL)head=temp;
else{
    temp->next=head;
    head=temp;
}
}

void insertl(int x){
node *temp=new node();
temp->data=x;
if(head==NULL)head=temp;
else{
    node *t=head;
    while(t->next!=NULL)t=t->next;
    t->next=temp;
}
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

node *reverselist(node *head){
if(head==NULL||head->next==NULL)return head;
node *curr=head,*next,*prev=NULL;
while(curr){
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
}
head=prev;
return prev;
}

void deletefront(){
if(head==NULL)return;
node *temp=head;
head=head->next;
delete(temp);
}

void deleteback(){
if(head==NULL)return;
node *temp=head;
if(head->next==NULL){
    head=head->next;
    delete(temp);
    return;
}
while(temp->next->next!=NULL)
    temp=temp->next;
node *temp1=temp;
temp=temp->next;
delete(temp);
temp1->next=NULL;
}

void reverseprintrecursive(node *head){
if(head==NULL)return;
reverseprintrecursive(head->next);
cout<<head->data<<" ";
}

void reverseprintiterative(){
if(!head)return;
stack<node*> s;
node *temp=head;
while(temp){
    s.push(temp);
    temp=temp->next;
}
while(!s.empty()){
    cout<<s.top()->data<<" ";
    s.pop();
}
cout<<"\n";
}

void deletelist(){
node *temp=head;
while(temp){
    node *next=temp->next;
    delete(temp);
    temp=next;
}
head=NULL;
}

void reverseinK(int k){
if(head==NULL||head->next==NULL||k==1)return;
node *nhead=NULL,*prev=NULL,*start=head,*next,*end;
int x=1;
while(head){
    while(x<k){
        ++x;
        head=head->next;
    }
    if(x==k){
        end=head;
        next=head->next;
        end->next=NULL;
        node *temp=reverselist(start);
        if(nhead==NULL)nhead=temp;
        if(prev)prev->next=temp;
        prev=start;
        start=next;
        head=next;
        x=1;
    }
}
head=nhead;
}

void checkpalindromelinkedlist(node *head){
if(head==NULL||head->next==NULL){
    cout<<"PALINDROME\n";
    return;
}
if(head->next->next==NULL){
     if(head->data==head->next->data)cout<<"PALINDROME\n";
     else cout<<"NOT PALINDROME\n";
    return;
}
node *curr=head,*mid=head,*prev,*newcurr,*temp;

while(curr!=NULL&&curr->next!=NULL){
    prev=mid;
    mid=mid->next;
    curr=curr->next->next;
}
prev->next=NULL;

newcurr=reverselist(mid);
temp=newcurr;
int y=1;
curr=head;
while(curr!=NULL&&newcurr!=NULL){
    if(curr->data!=newcurr->data){
        y=0;
        break;
    }
    curr=curr->next;
    newcurr=newcurr->next;
}
temp=reverselist(temp);
prev->next=temp;
if(y)cout<<"PALINDROME\n";
else cout<<"NOT PALINDROME\n";
}

void removeduplicatesinsortedlist(node *head){
if(head==NULL||head->next==NULL)return;
node *temp,*next;
while(head&&head->next){
    next=head->next;
    while(next!=NULL&&head->data==next->data){
        temp=next;
        next=next->next;
        delete(temp);
    }
    head->next=next;
    head=next;
}
}

node *deletenodehavingduplicatevaluesinsortedist(node *head){
if(head==NULL||head->next==NULL)return head;
node *temp,*next,*prev=NULL;
node *nhead=NULL;
while(head){
    next=head->next;
    if(next==NULL){
        if(prev==NULL)return head;
        prev->next=head;
        return nhead;
    }
    if(next->data!=head->data){
        if(prev==NULL)nhead=head;
        else prev->next=head;
        prev=head;
        head=head->next;
    }
    else{
        int data=head->data;
        while(head&&head->data==data){
            temp=head;
            head=head->next;
            delete(temp);
        }
    }
}
if(prev)prev->next=NULL;
return nhead;
}

int sizeoflinkedlist(node *head){
int x=0;
while(head){
    ++x;
    head=head->next;
}
return x;
}

node *rotaterightbykplaces(node *head,int k){
if(head==NULL||head->next==NULL)return head;
int n=sizeoflinkedlist(head);
k%=n;
if(!k)return head;
int y=0;
node *last,*prev=NULL,*nhead=NULL,*start=head;
while(head){
    ++y;
    if(y==n+1-k)
        nhead=head;
    if(nhead==NULL)prev=head;
    if(head->next==NULL)last=head;
    head=head->next;
}
prev->next=NULL;
last->next=start;
return nhead;
}

node *rotateleftbykplaces(node *head,int k){
if(head==NULL||head->next==NULL)return head;
int n=sizeoflinkedlist(head);
k%=n;
if(!k)return head;
int y=0;
node *last,*prev=NULL,*nhead=NULL,*start=head;
while(head){
    ++y;
    if(y==k+1)nhead=head;
    if(nhead==NULL)prev=head;
    if(head->next==NULL)last=head;
    head=head->next;
}
prev->next=NULL;
last->next=start;
return nhead;
}


node *reverselistfrommton(node *head,int m,int n){
if(head==NULL||head->next==NULL||m==n)return head;
int x=0;
node *nroot=head;
node *start,*prev=NULL,*next=NULL,*endm;
while(head){
    ++x;
    if(x==m)start=head;
    if(x==n)endm=head;
    if(x==n+1)next=head;
    if(x==m-1)prev=head;
    head=head->next;
}
endm->next=NULL;
node *temp=reverselist(start);
if(prev)prev->next=temp;
else nroot=temp;
start->next=next;
return nroot;
}

node *reorderlist(node *head){//original lits l1 l2 l3 l4 l5  reordered list l1 l5 l2 l4 l3
if(head==NULL||head->next==NULL)return head;
node *nhead=head;
node *curr=head,*mid=head,*prev=NULL,*next=NULL;
while(curr&&curr->next){
    mid=mid->next;
    curr=curr->next->next;
}
curr=mid->next;
mid->next=NULL;
curr=reverselist(curr);
mid=head;
mid=mid->next;
int x=0;
node* ncurr=head;
while(mid&&curr){
    if(x==0){
        ncurr->next=curr;
        curr=curr->next;
    }
    else{
        ncurr->next=mid;
        mid=mid->next;
    }
    ncurr=ncurr->next;
    x^=1;
}
while(mid){
    ncurr->next=mid;
    mid=mid->next;
    ncurr=ncurr->next;
}
while(curr){
    ncurr->next=curr;
    curr=curr->next;
    ncurr=ncurr->next;
}
return nhead;
}

node *swaplistinpairs(node *head){
if(head==NULL||head->next==NULL)return head;
node *nhead=head->next,*prev=NULL;
while(head&&head->next){
    node *next=head->next->next;
    node *temp=head->next;
    if(prev!=NULL)prev->next=temp;
    head->next=next;
    temp->next=head;
    prev=head;
    head=next;
}
return nhead;
}

node *detectcycle(node *head){
if(head==NULL||head->next==NULL){
cout<<"NO CYCLE DETECTED\n";
return NULL;
}
node *slow=head,*fast=head;
while(slow&&fast&&fast->next){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
        cout<<"CYCYLE DETECTED\n";
        return slow;
    }
}
cout<<"NO CYCLE DETECTED\n";
return NULL;
}

node *detectandremovecycle(node *head){
if(head==NULL||head->next==NULL)return head;
node *temp=detectcycle(head);
if(temp==NULL)return  head;
node *slow=head,*fast=temp;
while(1){
fast=temp;
while(fast->next!=temp&&fast->next!=slow)
    fast=fast->next;
    if(fast->next==slow)break;
    slow=slow->next;
}
fast->next=NULL;
return head;
}

node *sortusinginsertionsort(node *head){
if(head==NULL||head->next==NULL)return head;
node *temp,*next,*prev=head,*nhead=NULL,*curr=head->next;
while(curr){
    next=curr->next;
    if(curr->data<prev->data){
        nhead=head;
        temp=NULL;
        while(nhead!=NULL){
            if(nhead->data>curr->data)
                break;
            temp=nhead;
            nhead=nhead->next;
        }
        if(temp==NULL){
            head=curr;
            curr->next=nhead;
            prev->next=next;
            curr=next;
        }
        else{
            temp->next=curr;
            curr->next=nhead;
            prev->next=next;
            curr=next;
        }
    }
    else {
        prev=curr;
        curr=next;
    }
}
return head;
}

node *partitionbasedonk(node *head,int k){//without changing the relative order
if(head==NULL||head->next==NULL)return head;
node *head1=NULL,*head2=NULL,*curr=head,*curr1=NULL,*curr2=NULL,*next;
while(curr){
    next=curr->next;
    if(curr->data<k){
        if(head1==NULL){
            head1=curr;
            curr1=curr;
        }
        else {
            curr1->next=curr;
        curr1=curr;
        }
        curr->next=NULL;
    }
    else{
        if(head2==NULL){
            head2=curr;
            curr2=curr;
        }
        else {
            curr2->next=curr;
            curr2=curr;
        }
        curr->next=NULL;
    }
    curr=next;
}
if(head1==NULL)return head2;
if(head2==NULL)return head1;
head=head1;
curr1->next=head2;
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

int main(){
//sp;
head=NULL;
while(1){
    int c,x;
    cin>>c;
    if(c==1)display(head);
    else if(c==2){
        cin>>x;
        insertb(x);
    }
    else if(c==3){
        cin>>x;
        insertl(x);
    }
    else if(c==4)head=reverselist(head);
    else if(c==5)deletefront();
    else if(c==6)deleteback();
    else if(c==7){reverseprintrecursive(head);
   cout<<"\n"; }
    else if(c==8)reverseprintiterative();
    else if(c==9)deletelist();
    else if(c==10){
        int k;
        cin>>k;
        reverseinK(k);
    }
    else if(c==11)checkpalindromelinkedlist(head);
    else if(c==12)removeduplicatesinsortedlist(head);
    else if(c==13)head=deletenodehavingduplicatevaluesinsortedist(head);
    else if(c==14){
            int k;
             cin>>k;
            head=rotaterightbykplaces(head,k);
    }
    else if(c==15){
        int k;
        cin>>k;
        head=rotateleftbykplaces(head,k);
    }
    else if(c==16)cout<<sizeoflinkedlist(head)<<"\n";
    else if(c==17){
        int m,n;
        cin>>m>>n;
        head=reverselistfrommton(head,m,n);
    }
    else if(c==18)head=reorderlist(head);
    else if(c==19)head=swaplistinpairs(head);
    else if(c==20){
        if(head->next!=NULL){
         node *last;
         node *temp=head;
         while(temp){
            last=temp;
            temp=temp->next;
         }
         last->next=head;
        detectcycle(head);
        last->next=NULL;
        }
    }
    else if(c==21){
            if(head->next!=NULL){
         node *last;
         node *temp=head;
         int x=2;
         node *temp1=NULL;
         while(temp){
            last=temp;
            temp=temp->next;
            --x;
            if(x==0)temp1=temp;
         }
         last->next=temp1;
        head=detectandremovecycle(head);
        }
    }
    else if(c==22)head=sortusinginsertionsort(head);
    else if(c==23){
            int k;
            cin>>k;
            head=partitionbasedonk(head,k);
    }
    else if(c==24)head=mergesortonlinkedlist(head);
    else break;
}
return 0;}
