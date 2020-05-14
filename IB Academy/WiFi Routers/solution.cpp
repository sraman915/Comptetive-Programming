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

int func(int n,int m,vector<vector<int> > &C,vector<vector<int> > &D){
    int flag[109][109]={};
        vector<int> x;
        vector<int> y;
        vector<int> c;
        for(int i=0; i<n; i++){
            int temp1=C[i][0];
            int temp2=C[i][1];
            assert(temp1>=0 && temp1<=100);
            assert(temp2>=0 && temp2<=100);
            if(flag[temp1][temp2]==1)
                assert(-1>0);
            flag[temp1][temp2]=1;
            x.push_back(temp1);
            y.push_back(temp2);
            c.push_back(1);
        }
        for(int i=0; i<m; i++){
            int temp1=D[i][0];
            int temp2=D[i][1];
            assert(temp1>=0 && temp1<=100);
            assert(temp2>=0 && temp2<=100);
            if(flag[temp1][temp2]==1)
                assert(-1>0);
            flag[temp1][temp2]=1;
            x.push_back(temp1);
            y.push_back(temp2);
            c.push_back(0);
        }
        assert((int)c.size()==(n+m));
        int n1=(int)x.size();
        int d[n1][n1];
        for (int i=0; i<n1; i++)
            for (int j=0; j<n1; j++)
                d[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
        for (int i=0; i<n1; i++)  if (c[i]==0)
            for (int j=0; j<n1; j++)
                for (int k=0; k<n1; k++)
                    d[j][k]=min(d[j][k], max(d[j][i], d[i][k]));
        int sol=0;
        for (int i=0; i<n1; i++)
            for (int j=0; j<n1; j++)
                if (c[i]==0 && c[j]==1)
                    sol=max(sol, d[i][j]);
        assert(sol>=0&&sol<=INT_MAX);
        return sol;
}

int solveit(int A,int B,vector<vector<int> > &C,vector<vector<int> > &D){
    return func(A,B,C,D);
}

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
    int n,m,tm,tn,temp;
    vector<vector<int> > c,d;
    cin>>n>>m;
    assert(n>=1&&n<=100);
    assert(m>=1&&m<=100);
    cin>>tn>>temp;
    assert(tn==n);
    assert(temp==2);
    for(int i=0; i<n; ++i){
        int x,y;
        cin>>x>>y;
        vector<int> v;
        v.push_back(x);
        v.push_back(y);
        assert(x>=0&&x<=100);
        assert(y>=0&&y<=100);
        c.push_back(v);
    }
    cin>>tm>>temp;
    assert(tm==m);
    assert(temp==2);
    for(int i=0; i<m; ++i){
        int x,y;
        cin>>x>>y;
        vector<int> v;
        v.push_back(x);
        v.push_back(y);
        assert(x>=0&&x<=100);
        assert(y>=0&&y<=100);
        d.push_back(v);
    }
    assert(c.size()==n);
    assert(d.size()==m);
    int ans=solveit(n,m,c,d);
    assert(ans>=0&&ans<=INT_MAX);
    cout<<ans<<"\n";
}
return 0;}
