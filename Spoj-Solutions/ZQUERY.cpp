/*
ZQUERY - Zero Query
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mp make_pair
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf (ll)1e15
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 100200

int n,a[mxn],block,ans[mxn];
deque<int> dq[mxn];
multiset<int> m;
struct query{
int l,r,id;
};

bool compare(query a,query b){
int x=a.l/block;
int y=b.l/block;
if(x==y)
    return a.r<b.r;
return x<y;
}

int main(){
sp;
int n,t,l,r,temp;
cin>>n>>t;
block=ceil(sqrt(n+2));
for(int i=1; i<=n; ++i)
    cin>>a[i];
a[0]=50060;
for(int i=1; i<=n; ++i)
    a[i]+=a[i-1];
query q[t];
for(int i=0; i<t; ++i){
    cin>>q[i].l>>q[i].r;
    q[i].l--;
    q[i].id=i;
}
sort(q,q+t,compare);
int ml=0,mr=0;
dq[a[0]].push_front(0);
for(int i=0; i<t; ++i){
    l=q[i].l;
    r=q[i].r;
    while(mr<r){
        ++mr;
        if(dq[a[mr]].size()>1){
            temp=dq[a[mr]].back()-dq[a[mr]].front();
            m.erase(m.find(temp));
        }
        dq[a[mr]].pb(mr);
        if(dq[a[mr]].size()>1){
            temp=dq[a[mr]].back()-dq[a[mr]].front();
            m.insert(temp);
        }
    }
    while(ml>l){
                --ml;
        if(dq[a[ml]].size()>1){
            temp=dq[a[ml]].back()-dq[a[ml]].front();
            m.erase(m.find(temp));
        }
        dq[a[ml]].push_front(ml);
        if(dq[a[ml]].size()>1){
            temp=dq[a[ml]].back()-dq[a[ml]].front();
            m.insert(temp);
        }
    }
        while(ml<l){
        if(dq[a[ml]].size()>1){
            temp=dq[a[ml]].back()-dq[a[ml]].front();
            m.erase(m.find(temp));
        }
        dq[a[ml]].pop_front();
        if(dq[a[ml]].size()>1){
            temp=dq[a[ml]].back()-dq[a[ml]].front();
            m.insert(temp);
        }
        ++ml;
    }
        while(mr>r){
        if(dq[a[mr]].size()>1){
            temp=dq[a[mr]].back()-dq[a[mr]].front();
            m.erase(m.find(temp));
        }
        dq[a[mr]].pop_back();
        if(dq[a[mr]].size()>1){
            temp=dq[a[mr]].back()-dq[a[mr]].front();
            m.insert(temp);
        }
        --mr;
    }
    if(!m.empty())
ans[q[i].id]=*m.rbegin();
}
for(int i=0; i<t; ++i)
    cout<<ans[i]<<"\n";

return 0;}
