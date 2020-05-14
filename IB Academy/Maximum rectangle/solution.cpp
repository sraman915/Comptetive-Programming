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

int largest_rectangle(vector<int>hist)
    {
        //print_hist(hist);
        int top, max_area =-1, area,i;
        stack<int>st;//store index
        for(i = 0; i < hist.size(); i++)
        {
            if(st.empty() || hist[st.top()] <= hist[i])
                st.push(i);
            else
            {//upto stack becomes empty or current value >= stack top value
                while(!st.empty() && hist[i] < hist[st.top()])
                {
                    top = st.top();
                    st.pop();
                    if(st.empty())
                        area = hist[top] * i;//when stack empty
                    else
                        area = hist[top] * (i - st.top() -1);
                    max_area = max_area > area ? max_area : area ;
                }
                st.push(i); //current index
            }

        }
        //same as above code
        while(!st.empty())
        {
            top = st.top();
            st.pop();
            if(st.empty())
                area = hist[top] * i;
            else
                area = hist[top] * (i - st.top() -1);
            max_area = max_area > area ? max_area : area;
        }
        //cout<<max_area<<endl;
        return max_area;
    }

int maximalRectangle(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        int row = matrix.size(),col=matrix[0].size(),flag=0;
        //cout<<row<<" "<<col<<endl;
        if(row > col)
        {
            swap(row,col);
            flag=1;
        }
        //cout<<row<<" "<<col<<endl;
        int i,j,max_area=0;
        vector<int>hist(col,0);
        for(i = 0; i < row; i++)
        {
            for(j = 0; j < col; j++)
            {
                char c;
                if(flag)
                    c= matrix[j][i]; //if row > col
                else
                    c = matrix[i][j];
                //cout<<c<<' ';
                hist[j] = (c ==0) ? 0 : hist[j]+1;
            }
            //cout<<endl;
            max_area = max(max_area, largest_rectangle(hist));
//            print_hist(hist);
        }
        return max_area;
    }


int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
int n,m;
cin>>n>>m;
assert(n>=1&&n<=1000);
assert(m>=1&&m<=1000);
vector<vector<int> >matrix(n,vector<int>(m));
for(int i=0; i<n; ++i)
for(int j=0; j<m; ++j)cin>>matrix[i][j];
cout<<maximalRectangle(matrix)<<"\n";

}
return 0;}

