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
node *left,*right;
node(){
data=0;
left=NULL;
right=NULL;
}
node(int ndata){
data=ndata;
left=NULL;
right=NULL;
}
};
queue<node*> q;

node *insert(node *root,int x){
node *temp=new node(x);
if(root==NULL)
    root=temp;
else{
    node *temp1=q.front();
    if(temp1->left==NULL)temp1->left=temp;
    else if(temp1->right==NULL)temp1->right=temp;
    if(temp1->left&&temp1->right)q.pop();
}
q.push(temp);
return root;
}

void del(node *root){
if(root==NULL)return NULL;
del(root->left);
del(root->right);
delete(root);
}

void recursivepreorder(node *root){
if(root==NULL)return;
cout<<root->data<<" ";
recursivepreorder(root->left);
recursivepreorder(root->right);
}

void recursiveinorder(node *root){
if(root==NULL)return;
recursiveinorder(root->left);
cout<<root->data<<" ";
recursiveinorder(root->right);
}

void recursivepostorder(node *root){
if(root==NULL)return;
recursivepostorder(root->left);
recursivepostorder(root->right);
cout<<root->data<<" ";
}

void printiterativelevelorder(node *root){
if(root==NULL)return;
queue<node*> q;
q.push(root);
while(!q.empty()){
    q.push(NULL);
    while(q.front()!=NULL){
        node *temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);
    }
    cout<<"\n";
    q.pop();
}
cout<<"\n";
}

void printreverselevelorder(node *root){
if(root==NULL)return;
stack<node*> s;
queue<node*> q;
q.push(root);
while(!q.empty()){
    q.push(NULL);
    while(q.front()!=NULL){
        node *temp=q.front();
        q.pop();
        s.push(temp);
        if(temp->right)q.push(temp->right);
        if(temp->left)q.push(temp->left);
    }
    s.push(NULL);
    q.pop();
}
while(!s.empty()){
    if(s.top()==NULL)cout<<"\n";
    else cout<<s.top()->data<<" ";
s.pop();
}
cout<<"\n";
}

void printzigzagtraversal(node *root){
    if(root==NULL)return ;
    stack<node*> s1,s2;
    int y=0;
    s1.push(root);
    while(!s1.empty()||(!s2.empty())){
        if(y==0){
                y=1;
            while(!s1.empty()){
            node *temp=s1.top();
            cout<<temp->data<<" ";
            s1.pop();
            if(temp->left)s2.push(temp->left);
            if(temp->right)s2.push(temp->right);
            }
            cout<<"\n";
        }
        else{
            y=0;
            while(!s2.empty()){
            node *temp=s2.top();
            cout<<temp->data<<" ";
            s2.pop();
            if(temp->right)s1.push(temp->right);
            if(temp->left)s1.push(temp->left);
            }
            cout<<"\n";
        }
    }
    cout<<"\n";
}

void printzigzagtraversalusingonlyonestack(node *root){
    if(root==NULL)return ;
    stack<int> s1;
    queue<node*> q;
    int y=0;
    q.push(root);
    while(!q.empty()){
        q.push(NULL);
        while(q.front()!=NULL){
            node *temp=q.front();
            q.pop();
            if(y)s1.push(temp->data);
            else cout<<temp->data<<" ";
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        q.pop();
        if(y==0)cout<<"\n";
        else{
            while(!s1.empty()){
                cout<<s1.top()<<" ";
                s1.pop();
            }
            cout<<"\n";
        }
        y^=1;

    }
    cout<<"\n";
}

void reversezigzagtraversal(node *root){
if(root==NULL)return;
stack<node*> s;
queue<node*> q;
q.push(root);
s.push(root);
while(!q.empty()){
    q.push(NULL);
    s.push(NULL);
    while(q.front()!=NULL){
    node *temp=q.front();
    q.pop();
    if(temp->left){
        q.push(temp->left);
        s.push(temp->left);
    }
    if(temp->right){
        q.push(temp->right);
        s.push(temp->right);
    }
    }
    q.pop();
}
while(!s.empty()){
        if(s.top()==NULL)cout<<"\n";
    else cout<<s.top()->data<<" ";
        s.pop();
}
cout<<"\n";
}

void iterativepreorder(node *root){
if(root==NULL)return;
stack<node*> s;
s.push(root);
while(!s.empty()){
    node *temp=s.top();
    s.pop();
    cout<<temp->data<<" ";
    if(temp->right)s.push(temp->right);
    if(temp->left)s.push(temp->left);
}
cout<<"\n";
}

void iterativeinorder(node *root){
if(root==NULL)return;
stack<node*> s;
while(root){
    s.push(root);
    root=root->left;
}
while(!s.empty()){
    node *temp=s.top();
    s.pop();
    cout<<temp->data<<" ";
    if(temp->right){
        temp=temp->right;
    while(temp){
        s.push(temp);
        temp=temp->left;
    }
    }
}
cout<<"\n";
}

void iterativepostorder(node *root){
if(root==NULL)return;
stack<node*> s1,s2;
s1.push(root);
while(!s1.empty()){
    node *temp=s1.top();
    s1.pop();
    s2.push(temp);
    if(temp->left)s1.push(temp->left);
    if(temp->right)s1.push(temp->right);
}
while(!s2.empty()){
    cout<<s2.top()->data<<" ";
    s2.pop();
}
cout<<"\n";
}

void verticalordertraversal(node *root){
map<int,vector<int> > mp;
queue<pair<node*,int> > q;
if(!root)return;
q.push({root,0});
while(!q.empty()){
    pair<node*,int> p=q.front();
    q.pop();
    mp[p.second].pb(p.first->data);
    if(p.first->left)q.push({p.first->left,p.second-1});
    if(p.first->right)q.push({p.first->right,p.second+1});
}
for(auto &it:mp){
    for(auto &it1:it.s)cout<<it1<<" ";
 cout<<"\n";
}
cout<<"\n";
}

int heightoftreerecursive(node *root){
if(root==NULL)return 0;
int l=heightoftreerecursive(root->left);
int r=heightoftreerecursive(root->right);
return max(l,r)+1;
}

int heightoftreeiterative(node *root){
if(root==NULL)return 0;
queue<pair<node*,int> > q;
int h=0;
q.push({root,1});
while(!q.empty()){
    pair<node*,int> p=q.front();
    q.pop();
    h=max(h,p.second);
    if(p.first->left)q.push({p.first->left,p.second+1});
    if(p.first->right)q.push({p.first->right,p.second+1});
}
return h;
}
bool flag;

int balanced(node *root){
if(root==NULL||flag==0)return 0;
int lh=balanced(root->left);
int rh=balanced(root->right);
if(abs(lh-rh)>1){
    flag=0;
    return 0;
}
return max(lh,rh)+1;
}

void invertbinarytree(node *root){
if(!root)return;
queue<node*> q;
q.push(root);
while(!q.empty()){
    node *temp=q.front();
    q.pop();
    node *temp1=temp->left;
    temp->left=temp->right;
    temp->right=temp1;
    if(temp->left)q.push(temp->left);
    if(temp->right)q.push(temp->right);
}
}

void invertbinarytreerecursive(node *root){
if(root==NULL)return;
node *temp;
invertbinarytreerecursive(root->left);
invertbinarytreerecursive(root->right);
temp=root->left;
root->left=root->right;
root->right=temp;
}

void inorderthreadedtreetraversal(node *root){
if(!root)return;
node *curr=root,*pre=root;
while(curr!=NULL){
    if(curr->left==NULL){
        cout<<curr->data<<" ";
        curr=curr->right;
    }
    else{
        pre=curr->left;
        while(pre->right!=NULL&&pre->right!=curr)
            pre=pre->right;
        if(pre->right==NULL){
            pre->right=curr;
            curr=curr->left;
        }
        else{
            pre->right=NULL;
            cout<<curr->data<<" ";
            curr=curr->right;
        }
    }
}
cout<<"\n";
}


void preorderthreadedtreetraversal(node *root){
if(!root)return;
node *curr=root,*pre=root;
while(curr!=NULL){
    if(curr->left==NULL){
        cout<<curr->data<<" ";
        curr=curr->right;
    }
    else{
        pre=curr->left;
        while(pre->right!=NULL&&pre->right!=curr)
            pre=pre->right;
        if(pre->right==curr){
            pre->right=NULL;
            curr=curr->right;
        }
        else{
            pre->right=curr;
            cout<<curr->data<<" ";
            curr=curr->left;
        }
    }
}
cout<<"\n";
}

int main(){
//sp;
node *root=NULL;
while(1){
        int c;
        cin>>c;
        if(c==1){
            int n;
            cin>>n;
            for(int i=1; i<=n; ++i){
            int x;
            cin>>x;
            root=insert(root,x);
            }
        }
        else if(c==2){
                recursivepreorder(root);
                cout<<"\n";
        }
        else if(c==3){
                recursiveinorder(root);
                cout<<"\n";
        }
        else if(c==4){
                recursivepostorder(root);
                cout<<"\n";
        }
        else if(c==5)printiterativelevelorder(root);
        else if(c==6)iterativepreorder(root);
        else if(c==7)iterativeinorder(root);
        else if(c==8)iterativepostorder(root);
        else if(c==9)verticalordertraversal(root);
        else if(c==10)cout<<heightoftreeiterative(root)<<"\n";
        else if(c==11)cout<<heightoftreerecursive(root)<<"\n";
        else if(c==12)printreverselevelorder(root);
        else if(c==13)printzigzagtraversal(root);
        else if(c==14)printzigzagtraversalusingonlyonestack(root);
        else if(c==15)reversezigzagtraversal(root);
        else if(c==16){
            flag=1;
         balanced(root);
        if(flag)cout<<"BALANCED\n";
        else cout<<"NOT BALANCED\n";
        }
        else if(c==17)invertbinarytree(root);
        else if(c==18)invertbinarytreerecursive(root);
        else if(c==19)inorderthreadedtreetraversal(root);
        else if(c==20)preorderthreadedtreetraversal(root);
        else if(c==21){
            del(root);
            root=NULL;
            while(!q.empty())q.pop();
        }

        else break;
}
return 0;}
