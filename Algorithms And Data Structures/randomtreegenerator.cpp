#include<bits/stdc++.h>
using namespace std;

#define int long long
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
#define mxn 100005


void generate_random_tree(int n){
    vector<int> v1, v2;
    for(int i = 1; i <= n; ++i)
        v2.push_back(i);

    int x = n;
    while(x--){
        if(v1.empty()){
            int n1 = v2.size();
            int p = rand() % n1;
            v1.push_back(v2[p]);
            swap(v2[p], v2[n1-1]);
            v2.pop_back();
        }
        else{
            int n1 = v1.size();
            int n2 = v2.size();
            int p1 = rand()%n1;
            int p2 = rand()%n2;
            cout<<v1[p1]<<" "<<v2[p2]<<"\n";
            swap(v2[p2], v2[n2-1]);
            v1.push_back(v2.back());
            v2.pop_back();
        }
    }
}

int32_t main(){
sp;
    int n = 10;
    generate_random_tree(n);
return 0;}
