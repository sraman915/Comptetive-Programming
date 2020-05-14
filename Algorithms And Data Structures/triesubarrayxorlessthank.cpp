#include<bits/stdc++.h>
using namespace std;
# define I 20
struct node{
struct node* bit[2];
long long int countb[2];
};
struct node * getnode(void){
struct node *temp=  NULL;
temp=(struct node*)malloc(sizeof(struct node));
    temp->bit[0]=NULL;
    temp->bit[1]=NULL;
    temp->countb[0]=0;
    temp->countb[1]=0;
return temp;
}
void insert1(struct node* root,int n){
struct node*temp=root;
int i=0;
bool v;
for(i=I;i>=0;i--){
     v=n&(1<<i);
    if(!temp->bit[v]){
        temp->bit[v]=getnode();
    }
    temp->countb[v]++;
    temp=temp->bit[v];

}
}
long long int query1(struct node*root,int q,int k){
struct node*temp=root;
int i=0;
long long int ans=0;
bool c;
for(i=I;i>=0;i--){
    bool v1=q&(1<<i);
    bool v2=k&(1<<i);
    if(v1==1&&v2==0){
        c=1;
    }
    else if(v1==1&&v2==1){
        ans+=temp->countb[1];
        c=0;
    }
    else if(v1==0&&v2==0){
        c=0;
    }
    else if(v1==0&&v2==1){
        ans+=temp->countb[0];
        c=1;
    }
    if(temp->bit[c]!=NULL)
        temp=temp->bit[c];
    else
    break;
}
return ans;
}
int main(){
int t;
cin>>t;
while(t--){
    struct node* root=getnode();
    insert1(root,0);
    int n,k,i;
    cin>>n>>k;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
        int p=0;
        long long int ans=0;
    for(i=0;i<n;i++){
        p=p^arr[i];
        ans+=query1(root,p,k);
        insert1(root,p);
    }
    cout<<ans<<endl;
}
}
