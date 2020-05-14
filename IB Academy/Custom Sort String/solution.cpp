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

string customSortString(string &A, string &B) {
    int a[26]={0};
    for(auto &it:B)
        ++a[it-'a'];
    string ans;
    for(auto &it:A){
        while(a[it-'a']--)
            ans.push_back(it);
    }
    for(int i=0; i<26; ++i){
        if(a[i]>0){
            while(a[i]--)
                ans.push_back(i+'a');
        }
    }
    return ans;
}

string solve(string &A,string &B){
    assert(A.size()>=1&&A.size()<=26);
    assert(B.size()>=1&&B.size()<=100000);
    int a[26]={0};
    for(auto &it:A){
        assert(it>='a'&&it<='z');
        ++a[it-'a'];
    }
    for(auto &it:B)
        assert(it>='a'&&it<='z');
    for(auto &it:a)
        assert(it>=0&&it<=1);
    return customSortString(A,B);
}



int32_t main(){
sp;
freopen("input1.txt","r",stdin);
freopen("output1.txt","w",stdout);
int t;
cin>>t;
while(t--){
    string A,B;
    cin>>A>>B;
    cout<<solve(A,B);
    cout<<"\n";
}
return 0;}
