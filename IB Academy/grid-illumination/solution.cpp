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

vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<int> retv;
         // like N queen question . in this part we use  four map,each map have his idea
        long long N = n ;
        unordered_map<long,unordered_set<long long>> row,col,dia1,dia2; //dia1 means x-y = constant
        for(auto lamp : lamps)
        {
            row[lamp[0]].insert(N * lamp[0]+lamp[1]);
            col[lamp[1]].insert(N * lamp[0]+lamp[1]);
            dia1[lamp[0]-lamp[1]].insert(N*lamp[0]+lamp[1]);
            dia2[lamp[0]+lamp[1]].insert(N * lamp[0]+lamp[1]);
        }
        vector<vector<int> > dirs = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
        for(auto query : queries)
        {
            long x = query[0];
            long y = query[1];
            if(row.count(x) || col.count(y)||dia1.count(x-y)||dia2.count(x+y))
            {
                retv.push_back(1);
            }
            else
            {
                retv.push_back(0);
            }
            for(auto dir:dirs)
            {
                int dx = dir[0];
                int dy = dir[1];
                int dir_x = x+dx;
                int dir_y = y+dy;
                //four dir
                //row
                if(row.count(dir_x)&&row[dir_x].count(N * dir_x+dir_y))
                {
                    //erase lamp
                    row[dir_x].erase(N * dir_x+dir_y);
                    if(row[dir_x].size() == 0)
                    {
                        row.erase(dir_x);
                    }
                }
                if(col.count(dir_y)&&col[dir_y].count(N * dir_x+dir_y))
                {
                    //erase lamp
                    col[dir_y].erase(N * dir_x+dir_y);
                    if(col[dir_y].size() == 0)
                    {
                        col.erase(dir_y);
                    }
                }
                if(dia1.count(dir_x-dir_y)&&dia1[dir_x-dir_y].count(N * dir_x+dir_y))
                {
                    //erase lamp
                    dia1[dir_x-dir_y].erase(N * dir_x+dir_y);
                    if(dia1[dir_x-dir_y].size() == 0)
                    {
                        dia1.erase(dir_x-dir_y);
                    }
                }
                if(dia2.count(dir_x+dir_y)&&dia2[dir_x+dir_y].count(N * dir_x+dir_y))
                {
                    //erase lamp
                    dia2[dir_x+dir_y].erase(N * dir_x+dir_y);
                    if(dia2[dir_x+dir_y].size() == 0)
                    {
                        dia2.erase(dir_x+dir_y);
                    }
                }
            }
        }
        return retv;
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
assert(n>=1&&n<=1000000000);
vector<vector<int> > a,b;
int m,q,y;
cin>>m>>y;
assert(m>=1&&m<=20000);
for(int i=0;i<m; ++i){
vector<int> x;
int a1,a2;
cin>>a1>>a2;
assert(a1>=0&&a1<n);
assert(a2>=0&&a2<n);
x.pb(a1);
x.pb(a2);
a.pb(x);
}

cin>>q>>y;
assert(q>=1&&q<=20000);
for(int i=0;i<q; ++i){
vector<int> x;
int a1,a2;
cin>>a1>>a2;
assert(a1>=0&&a1<n);
assert(a2>=0&&a2<n);
x.pb(a1);
x.pb(a2);
b.pb(x);
}
vector<int> ans=gridIllumination(n,a,b);
for(auto &it:ans)cout<<it<<" ";
cout<<"\n";
}
return 0;}
