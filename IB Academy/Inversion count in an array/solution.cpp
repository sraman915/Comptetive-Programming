#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (long long )1000000007
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


int merge(vector<int> &a,int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    int ans=0;
    for(int i=0; i<n1; i++)
        L[i]=a[l+i];
    for(int i=0; i<n2; i++)
        R[i]=a[m+1+i];
    int i,j,k;
    i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(L[i]<=R[j]){
            a[k]=L[i++];
        }
        else{
            a[k]=R[j++];
            ans+=(n1-i);
            ans%=mod;
        }
        ++k;
    }
while(i<n1){
    a[k]=L[i];
    i++;
    k++;}
while(j<n2){
        a[k]=R[j];
        j++;
        k++;
    }
    ans=ans%mod;
    return ans;
}


int invcount(vector<int> &a,int l,int r){
if(l>=r){
    return 0;
}
int m=(l+r)>>1;
int leftcount=invcount(a,l,m);
int rightcount=invcount(a,m+1,r);
int leftright=merge(a,l,m,r);
return (leftcount+rightcount+leftright)%mod;
}

int solve(vector<int> &a){
int n=a.size();
return invcount(a,0,n-1);
}


int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
    vector<int> a;
    int n;
    cin>>n;
    for(int i=0; i<n; ++i){
        int x;
        cin>>x;
    a.pb(x);
    }
    cout<<solve(a)<<"\n";
}
return 0;}

