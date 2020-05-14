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

void merge(vector<int>& a, int start, int mid, int end)
{
    int n1 = (mid - start + 1);
    int n2 = (end - mid);
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = a[start + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];
    int i = 0, j = 0;
    for (int k = start; k <= end; k++) {
        if (j >= n2 || (i < n1 && L[i] <= R[j]))
            a[k] = L[i++];
        else
            a[k] = R[j++];
    }
}

int mergesort_and_count(vector<int>& a, int start, int end){
    if (start < end) {
        int mid = (start + end) / 2;
        int count = mergesort_and_count(a, start, mid) + mergesort_and_count(a, mid + 1, end);
        int j = mid + 1;
        for (int i = start; i <= mid; i++) {
            while (j <= end && a[i] > a[j] * 2LL)
                j++;
            count += j - (mid + 1);
        }
        merge(a, start, mid, end);
        return count;
    }
    else
        return 0;
}

int solve(vector<int>& a){
    return mergesort_and_count(a, 0, a.size() - 1);
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
    cout<<solve(a)<<"\n";
}
return 0;}

