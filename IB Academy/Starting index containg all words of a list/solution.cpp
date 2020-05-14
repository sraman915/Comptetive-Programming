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

void findSubstringIndices(string &S,  vector<string>& L) {

    // Number of a characters of a word in list L.
    int size_word = L[0].size();

    // Number of words present inside list L.
    int word_count = L.size();

    // Total characters present in list L.
    int size_L = size_word * word_count;

    // Resultant vector which stores indices.
    vector<int> res;

    // If the total number of characters in list L
    // is more than length of string S itself.
    if (size_L > S.size()) {
        cout<<"\n";
        }

    // Map stores the words present in list L
    // against it's occurrences inside list L
    unordered_map<string, int> hash_map;

    for (int i = 0; i < word_count; i++)
        hash_map[L[i]]++;

    for (int i = 0; i <= S.size() - size_L; i++) {
        unordered_map<string, int> temp_hash_map(hash_map);

        int j = i;

        // Traverse the substring
        while (j < i + size_L) {

            // Extract the word
            string word = S.substr(j, size_word);

            // If word not found simply break.
            if (hash_map.find(word) == hash_map.end())
                break;

            // Else decrement the count of word from hash_map
            else
                temp_hash_map[word]--;

            j += size_word;
        }

        int count = 0;
        for (auto itr = temp_hash_map.begin();
             itr != temp_hash_map.end(); itr++)
            if (itr->second > 0)
                count++;

        // Store the starting index of that substring
        if (count == 0)
            res.push_back(i);
    }
  for(auto &it:res)cout<<it<<" ";
  cout<<"\n";
   // return res;
}

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
string s;
cin>>s;
int n;
cin>>n;
vector<string> v(n);
for(int i=0; i<n; ++i)cin>>v[i];
findSubstringIndices(s,v);
}
return 0;}
