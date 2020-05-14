#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (long long)1000000007
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
#define mxn 500005

struct node
{
    node* a[2];
    int own,size;
};

void insert(node* root,string s,int indx){
    if(indx==s.size()){
        root->own+=1;
        root->size=root->own;
        return;
    }
    if(root->a[s[indx]-'0']){
        insert(root->a[s[indx]-'0'],s,indx+1);
        root->size=0;
        if(root->a[0])
        root->size+=root->a[0]->size;
        if(root->a[1])
        root->size+=root->a[1]->size;
    }
    else{
        node* p=new node;
        p->own=0;
        p->size=0;
        p->a[0]=NULL;
        p->a[1]=NULL;
        root->a[s[indx]-'0']=p;
        insert(p,s,indx+1);
        root->size=0;
        if(root->a[0])
        root->size+=root->a[0]->size;
        if(root->a[1])
        root->size+=root->a[1]->size;
    }
}

int querry(node* root,string s,string str,int indx){
    if(indx==s.size())
    return root->size;
    int ans1,ans2;
    ans1=0;
    ans2=0;
    if(root->a[0]){
        int k1=s[indx]-'0';
        if(k1<(str[indx]-'0'))
        ans1=root->a[0]->size;
        else if(k1>(str[indx]-'0'))
        ans1=0;
        else
        ans1=querry(root->a[0],s,str,indx+1);
        while(ans1>=mod)ans1-=mod;
    }
    if(root->a[1]){
        int k1=s[indx]-'0';
        k1^=1;
        if(k1<(str[indx]-'0'))
        ans2=root->a[1]->size;
        else if(k1>(str[indx]-'0'))
        ans2=0;
        else
        ans2=querry(root->a[1],s,str,indx+1);
        while(ans2>=mod)ans2-=mod;
    }
    return (ans1+ans2)%mod;
}

string tostring(int k){
    string tmp;
    while(k){
            if(k&1)
            tmp+='1';
            else
            tmp+='0';
            k>>=1;
        }
        while(tmp.size()<20)
        tmp+='0';
        reverse(tmp.begin(),tmp.end());
        return tmp;
}

int doit(vector<int> &a,int k){
        int n=a.size();
        --k;
        string tmp;
        tmp=tostring(k);
        node* root=new node;
        root->size=0;
        root->own=0;
        root->a[0]=NULL;
        root->a[1]=NULL;
        int pre=0;
        string s;
        int ans=0;
        for(int i=0;i<n;i++){
            int x=a[i];
            pre^=x;
            s=tostring(pre);
            ans+=querry(root,s,tmp,0);
            if(pre<=k)
            ans+=1;
            while(ans>=mod)
                ans-=mod;
            insert(root,s,0);
        }
    return ans;
}


int32_t main(){
sp;
freopen("input1.txt","r",stdin);
freopen("output.txt","w",stdout);
int t;
cin>>t;
while(t--){
int n,k;
cin>>n;
assert(n>=1&&n<=100000);
vector<int> a(n);
for(int i=0; i<n; ++i){
cin>>a[i];
assert(a[i]>=1&&a[i]<=100000);
}
cin>>k;
assert(k>=1&&k<=1000000);
cout<<doit(a,k)<<"\n";
}
return 0;}
