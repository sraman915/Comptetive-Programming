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

multimap<int, int, greater_equal<int>> st;
unordered_map<int, int> freq;


class maximum_frequency_stack{
	map<int,int> frequency;
	map<int, stack<int> > frequency_stack;
	int mx;

    maximum_frequency_stack(){
        frequency.clear();
        mx = 0;
        frequency_stack.clear();
    }

    void push(int val){
		++frequency[val];
		int y = frequency[val];
		mx = max(mx, y);
		frequency_stack[y].push(val);
    }

    int pop(){
        if(frequency.empty())
            return -1;
        int val = frequency_stack[mx].top();
        frequency_stack[mx].pop();
        --frequency[val];
        if(frequency[val] == 0)
            frequency.erase(val);
        if(frequency_stack[mx].empty())
            --mx;
        return val;
    }
};




void push(int x,vector<int> &ans){
    st.insert({++freq[x], x});
    ans.push_back(-1);
}

void pop(vector<int> &ans){
    int res = st.begin()->second;
    st.erase(st.begin());
    freq[res]--;
    ans.push_back(res);
}




int32_t main(){
sp;
//freopen("input3.txt","r",stdin);
//freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
st.clear();
freq.clear();
int n,m;
cin>>n>>m;
vector<int> ans;
int x,y;
for(int i=0; i<n; ++i){
cin>>x>>y;
if(x==1)push(y,ans);
else pop(ans);
}
for(auto &it:ans)cout<<it<<" ";
cout<<"\n";
}
return 0;}
