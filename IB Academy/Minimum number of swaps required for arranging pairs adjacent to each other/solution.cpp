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

void updateindex(vector<int> &index, int a, int ai, int b, int bi) {
    index[a] = ai;
    index[b] = bi;
}

int minSwapsUtil(vector<int> &A, vector<int> &pairs, vector<int> &index, int i, int n) {
    if (i > n)
        return 0;
    if (pairs[A[i]] == A[i+1])
         return minSwapsUtil(A, pairs, index, i+2, n);

    int one = A[i+1];
    int indextwo = i+1;

    int indexone = index[pairs[A[i]]];
    int two = A[index[pairs[A[i]]]];
    swap(A[i+1], A[indexone]);
    updateindex(index, one, indexone, two, indextwo);

    int a = minSwapsUtil(A, pairs, index, i+2, n);

    swap(A[i+1], A[indexone]);
    updateindex(index, one, indextwo, two, indexone);
    one = A[i], indexone = index[pairs[A[i+1]]];

    two = A[index[pairs[A[i+1]]]], indextwo = i;
    swap(A[i], A[indexone]);
    updateindex(index, one, indexone, two, indextwo);
    int b = minSwapsUtil(A, pairs, index, i+2, n);

    swap(A[i], A[indexone]);
    updateindex(index, one, indextwo, two, indexone);
    return 1 + min(a, b);
}

void convertToOneBased(vector<int> &a){
    reverse(a.begin(),a.end());
    a.push_back(0);
    reverse(a.begin(),a.end());
}


vector<int> convertToPairsBasedOnIndexing(vector<vector<int> > &b){
    int n=b.size();
    vector<int> pairs(n+n+1);
    for(int i=0; i<b.size(); ++i){
        pairs[b[i][0]]=b[i][1];
        pairs[b[i][1]]=b[i][0];
    }
    return pairs;
}

int solve(int A,vector<int> &B,vector<vector<int> > &C){
    convertToOneBased(B);
    vector<int> pairs=convertToPairsBasedOnIndexing(C);
    vector<int> index(A+A+1);
    for(int i=1; i<=A; ++i)
        index[B[i]]=i;
    return minSwapsUtil(B,pairs,index,1,2*A);
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
    assert(n>=1&&n<=20);
    int tn,tm;
    cin>>tn;
    assert(tn==n+n);
    vector<int> a(n+n);
    for(int i=0; i<tn; ++i)
        cin>>a[i];
    cin>>tn>>tm;
    assert(tn==n);
    assert(tm==2);
    vector<vector<int> > v(n,vector<int>(2));
    for(int i=0; i<n; ++i)
        for(int j=0; j<2; ++j)
            cin>>v[i][j];
    int ans=solve(n,a,v);
    cout<<ans<<"\n";
}
return 0;}
