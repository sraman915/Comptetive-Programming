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



class typeahead{
    public:
        int k;
        struct trie{
            trie *a[26];
            vector<pair<int,string> > sugg;
            trie(){
                sugg.clear();
                for(int i=0; i<26; ++i)
                    a[i]=NULL;
            }
        };
        trie *root;
        typeahead(){
            k=3;
            root=NULL;
        }
        typeahead(int y){
            k=y;
            root=NULL;
        }

        vector<pair<int,string> > suggestions(string &word);
        void preprocess(trie *root);
        void insertwords(vector<string> &words,vector<int>&ranks);
};



void typeahead::insertwords(vector<string> &words,vector<int> &ranks){
    root=new trie();
    trie *temp;
    for(int i=0; i<words.size(); ++i){
        string &word=words[i];
        temp=root;
        for(auto &ch:word){
            int c=ch-'a';
            if(temp->a[c]==NULL)
                temp->a[c]=new trie();
            temp=temp->a[c];
        }
        temp->sugg.push_back({ranks[i],word});
    }
    preprocess(root);
}

void typeahead::preprocess(trie *root){
    if(root==NULL)
        return;
    priority_queue<pair<int,string>,vector<pair<int,string> >, greater<pair<int,string> > > q;
    for(auto &it:root->sugg)
        q.push(it);
    for(int i=0; i<26; ++i){
        preprocess(root->a[i]);
        if(root->a[i]){
            vector<pair<int,string> > v1=root->a[i]->sugg;
            for(auto &it:v1){
                if(q.size()<k)
                    q.push(it);
                else{
                    if(q.top().first<it.first){
                        q.pop();
                        q.push(it);
                    }
                }
            }
        }
    }
    root->sugg.clear();
    while(!q.empty()){
        root->sugg.push_back(q.top());
        q.pop();
    }
    reverse(root->sugg.begin(),root->sugg.end());
}


vector<pair<int,string> >typeahead:: suggestions(string &word){
    trie *temp=root;
    vector<pair<int,string> > ans;
    for(auto &c:word){
        int x=c-'a';
        if(temp->a[x]==NULL)
            return ans;
        temp=temp->a[x];
    }
    ans=temp->sugg;
    return ans;
}

int32_t main(){
//sp;
    vector<string> words;
    vector<int> ranks;
    int n=10;
    for(int i=0; i<10; ++i){
        string x;
        int y;
        cin>>x>>y;
        words.push_back(x);
        ranks.push_back(y);
    }
    typeahead google(4);
    google.insertwords(words,ranks);
    while(1){
       string query;
       cin>>query;
       vector<pair<int,string> > v=google.suggestions(query);
       cout<<query<<"\n";
       for(auto &it:v){
        cout<<"\t";
        cout<<it.second<<"\t"<<it.first<<"\n";
       }
       cout<<"\n";
    }
    return 0;
}
