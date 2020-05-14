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

struct ListNode {
    int val;
    ListNode *next,*random;
    ListNode(int x) {
        val = x;
        next = random = NULL;
    }
};

void print(ListNode *start) {
    ListNode *ptr = start;
    while (ptr) {
        cout << "Data = " << ptr->val << ", Random  = "
             << ptr->random->val << endl;
        ptr = ptr->next;
    }
}

ListNode* clone(ListNode *start) {
    ListNode* curr = start, *temp;
    while (curr) {
        temp = curr->next;
        curr->next = new ListNode(curr->val);
        curr->next->next = temp;
        curr = temp;
    }

    curr = start;
    while (curr) {
        if(curr->next)
            curr->next->random = curr->random ?  curr->random->next : curr->random;
        curr = curr->next?curr->next->next:curr->next;
    }

    ListNode* original = start, *copyy = start->next;
    temp = copyy;

    while (original && copyy) {
        original->next = original->next? original->next->next : original->next;
        copyy->next = copyy->next?copyy->next->next:copyy->next;
        original = original->next;
        copyy = copyy->next;
    }

    return temp;
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
   ListNode* head=NULL;
   ListNode *prev=NULL;
   unordered_map<int,ListNode *> mp;
       for(int i=0; i<n; ++i){
             int x;
             cin>>x;
             ListNode *temp=new ListNode(x);
             mp[x]=temp;
             if(head==NULL)
               head=temp;
            else
               prev->next=temp;
        prev=temp;
      }

   ListNode *h=head;

      for(int i=0; i<n; ++i){
            int x;
            cin>>x;
            ListNode *temp=mp[x];
            h->random=temp;
            h=h->next;
       }

    ListNode *h2=clone(head);
    h=h2;
    int yy=0;
     while(h){
       if(yy)cout<<"-> ";
       cout<<h->val<<" ";
       h=h->next;
       yy=1;
    }
    h=h2;
   cout<<"\n";
     while(h){
        cout<<h->val<<" -> "<<h->random->val<<" ";
        h=h->next;
     }
  cout<<"\n";
}
return 0;}

