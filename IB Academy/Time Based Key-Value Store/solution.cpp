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

unordered_map<string,vector<int>> mytable;
unordered_map<string,unordered_map<int,string>> subtable;


int b_s(vector<int>&v , int target){
    int left = 0, right = v.size()-1;
    while(right >= left){
        int mid = (right+left)/2;
        if(v[mid] == target)
            return mid;
        else if(v[mid] > target)
            right = mid-1;
        else
            left = mid+1;
    }
    return right;
}

void binary_insert(vector<int>& v, int target){
    if(v.size() == 0 || target > v[v.size()-1])
        v.push_back(target);
    else if(target < v[0])
        v.insert(v.begin(),target);
    else
        v.insert(v.begin()+b_s(v,target),target);
}

void sett(string &key, string &value, int timestamp) {
    binary_insert(mytable[key],timestamp);
    subtable[key][timestamp] = value;
}





string get(string key, int timestamp) {
    if(mytable[key].size() == 0 || timestamp < mytable[key][0])
            return "null";
    else{
        int idx = b_s(mytable[key],timestamp);
        return subtable[key][mytable[key][idx]];
    }
}


vector<string> solveit(vector<int> &type,vector<string> &key,vector<string> &value,vector<int> &timestamp){
    int n=type.size();
    mytable.clear();
    subtable.clear();
    vector<string> ans;
    for(int i=0; i<n; ++i){
        if(type[i]==1){
            sett(key[i],value[i],timestamp[i]);
            ans.push_back("null");
            }
        else
            ans.push_back(get(key[i],timestamp[i]));
    }
    return ans;
}

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
    int n,tempn;
    cin>>n;
    assert(n>=1&&n<=100000);
    vector<int> type(n);
    vector<string> key(n);
    vector<string> value(n);
    vector<int> timestamp(n);
    for(int i=0; i<n; ++i){
        cin>>type[i];
        assert(type[i]>=1&&type[i]<=2);
    }
    cin>>tempn;
    assert(tempn==n);
    for(int i=0; i<n; ++i){
        cin>>key[i];
        assert(key[i].size()>=1&&key[i].size()<=50);
    }
    cin>>tempn;
    assert(tempn==n);
    for(int i=0; i<n; ++i){
        cin>>value[i];
        assert(value[i].size()>=1&&value[i].size()<=50);
    }
    cin>>tempn;
    assert(tempn==n);
    for(int i=0; i<n; ++i){
        cin>>timestamp[i];
        assert(timestamp[i]>=1&&timestamp[i]<=10000000);
    }
    vector<string> ans=solveit(type,key,value,timestamp);
    for(auto &it:ans)
        cout<<it<<" ";
    cout<<"\n";
}
return 0;}
