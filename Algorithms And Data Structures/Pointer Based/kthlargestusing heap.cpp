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

void heapify(int *a,int n,int i){
int l=2*i;
int r=2*i+1;
int small=i;
if(l<=n&&a[l]<a[small])small=l;
if(r<=n&&a[r]<a[small])small=r;
if(small!=i){
    swap(a[i],a[small]);
    heapify(a,n,small);
}
}

void removefromheap(int *a,int n){
a[1]=a[n--];
heapify(a,n,1);
}


int main(){
sp;
int n,k;
cin>>n>>k;
int b[n+1],a[k+1];
for(int i=1; i<=n; ++i)cin>>b[i];
for(int i=1; i<=k; ++i)
    a[i]=b[i];
for(int i=k/2; i>0; --i)heapify(a,k,i);
for(int i=k+1; i<=n; ++i){
    if(b[i]>a[1]){
        a[1]=b[i];
        heapify(a,k,1);
    }
}

cout<<"\n";
int sz=k;
for(int i=1; i<=k; ++i){
    cout<<a[1]<<" ";
    --sz;
    removefromheap(a,sz+1);
}

return 0;}
