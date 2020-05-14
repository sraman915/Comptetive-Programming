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

int prime[200];
int tc=0;
void pre(){
    if(tc)
        return;
    ++tc;
    prime[0]=prime[1]=1;
    for(int i=4; i<200; i+=2)
        prime[i]=1;
    for(int i=3; i*i<=200; i+=2)
        if(!prime[i])
            for(int j=i*i; j<200; j+=i)
                prime[j]=1;
}

bool isPrimeSumOfDigit(int x){
    int sum=0;
    while(x){
        int y=x%10;
        sum+=y;
        x/=10;
    }
    return (prime[sum]==0);
}

vector<int> solveit(vector<int> &a){
    pre();
    vector<int> ans1,ans2;
    for(auto &it:a){
        if(isPrimeSumOfDigit(it))
            ans1.push_back(it);
        else
            ans2.push_back(it);
    }
    for(auto &it:ans2)
        ans1.push_back(it);
    return ans1;
}

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    assert(n>=1&&n<=100000);
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin>>a[i];
        assert(a[i]>=1&&a[i]<=1000000000);
    }
    vector<int> ans=solveit(a);
    int prev=0;
    for(auto &it:ans){
        if(prev)
            cout<<"-> ";
        cout<<it<<" ";
        prev=1;
    }
    cout<<"\n";
}
return 0;}
