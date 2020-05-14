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

bool compare(int arr1[], int arr2[])
{
    for (int i=0; i<26; i++)
        if (arr1[i] != arr2[i])
            return false;
    return true;
}

// This function search for all permutations of pat[] in txt[]
void search(string &pat, string &txt)
{

vector<int> ans;
    int M = pat.size(), N = txt.size();
    for(auto &it:pat)assert(it>='a'&&it<='z');
    for(auto &it:txt)assert(it>='a'&&it<='z');
    assert(N>M);

    // countP[]:  Store count of all characters of pattern
    // countTW[]: Store count of current window of text
    int countP[26] = {0}, countTW[26] = {0};
    for (int i = 0; i < M; i++)
    {
        (countP[pat[i]-'a'])++;
        (countTW[txt[i]-'a'])++;
    }

    // Traverse through remaining characters of pattern
    for (int i = M; i < N; i++)
    {
        // Compare counts of current window of text with
        // counts of pattern[]
        if (compare(countP, countTW))
            ans.pb(i - M);

        // Add current character to current window
        (countTW[txt[i]-'a'])++;

        // Remove the first character of previous window
        countTW[txt[i-M]-'a']--;
    }

    // Check for the last window in text
    if (compare(countP, countTW))
        ans.pb(N - M);
        for(auto &it:ans)cout<<it<<" ";
        cout<<"\n";
}



int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
string a,b;
cin>>a>>b;
search(b,a);
}
return 0;}
