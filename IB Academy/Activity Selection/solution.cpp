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

int solveit(vector<int> &A,vector<int> &B){
    vector<pair<int,int> >ans;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    for(int i=0;i<A.size();i++)
        q.push(make_pair(B[i],A[i]));
    auto it = q.top();
    int start = it.second;
    int end = it.first;
    q.pop();
    ans.push_back(make_pair(start,end));
    while(!q.empty()){
        auto itr = q.top();
        q.pop();
        if(itr.second >= end){
            start = itr.second;
            end = itr.first;
            ans.push_back(make_pair(start,end));
        }
    }
    return (int)(ans.size());
}

int alternatesolution(vector<int> &A,vector<int> &B){
    struct activity{
        int start,finish;
    };
    int n=A.size();
    activity a[n];
    for(int i=0; i<n; ++i){
        a[i].start=A[i];
        a[i].finish=B[i];
    }
    sort(a,a+n,[&](const activity &x,const activity &y){
        return x.finish<y.finish;
    });
    int i=0;
    int ans=1;
    for(int j=1; j<n; ++j){
        if(a[j].start>=a[i].finish){
            ++ans;
            i=j;
        }
    }
    return ans;
}


int32_t main(){
sp;
//freopen("input3.txt","r",stdin);
//freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    assert(n>=1&&n<=100000);
    vector<int> A(n),B(n);
    for(int i=0; i<n; ++i)
        cin>>A[i];
    int tn;
    cin>>tn;
    assert(tn==n);
    for(int i=0; i<n; ++i){
        cin>>B[i];
        assert(B[i]>A[i]);
    }
    int ans=solveit(A,B);
    cout<<ans<<"\n";
}
return 0;}
