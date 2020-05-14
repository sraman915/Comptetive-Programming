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

typedef complex<double> base;

const double PI = acos(-1.0l);
const int N = 1005;


vector<int> rev;
vector<base> omega;

void calc_rev(int n, int log_n){ //Call this before FFT
	rev.resize(n);
	omega.resize(n);
	for(int i = 0; i < n;i++){
		rev[i] = 0;
		for(int j = 0; j < log_n; j++){
			if((i >> j) & 1)
				rev[i] |= 1<<(log_n - j - 1);
		}
	}
}

void fft(vector<base> &A, int n, bool invert){
	for(int i = 0;i < n; i++){
		if(i < rev[i])
			swap(A[i], A[rev[i]]);
	}
	for(int len = 2; len <= n; len <<= 1){
		double ang = 2 * PI / len * (invert? -1 : +1);
		int half = (len >> 1);

		base curomega(cos(ang), sin(ang));
		omega[0] = base(1, 0);

		for(int i = 1; i < half;i++)
			omega[i] = omega[i - 1] * curomega;

		for(int i = 0; i < n; i += len){
			base t;
			int pu = i, pv = i+half, pu_end = i+half, pw = 0;
			for(; pu != pu_end; pu++, pv++, pw++){
				t = A[pv] * omega[pw];
				A[pv] = A[pu] - t;
				A[pu] += t;
			}
		}
	}

	if(invert)
		for(int i = 0;i < n;i++)
			A[i] /= n;
}

void multiply(int n, vector<base> &A, vector<base> &B, vector<int> &C){
	fft(A, n, false);
	fft(B, n, false);
	for(int i = 0; i < n; i++)
		A[i] *= B[i];
	fft(A, n, true);
	for(int i = 0; i < n; i++){
		C[i] = (int)(A[i].real() + 0.5);
		C[i] = min(C[i], 1LL);
	}
}

void Solve(int n, vector<int> &coeffA, vector<int> &coeffB, vector<int> &result){
	vector<base> A(n), B(n);
	for(int i = 0; i < n; i++)
		A[i] = coeffA[i];
	for(int i = 0; i < n; i++)
		B[i] = coeffB[i];
	multiply(n, A, B, result);
}

void do_FFT(vector<int> &A, vector<int> &B, vector<int> &result){
	int n = 1, bits = 0;
	while(n < 2*A.size() || n < 2*B.size())
		n <<= 1, bits++;
	result.resize(n, 0);
	calc_rev(n, bits);
	vector<int> tempA(A.begin(), A.end());
	vector<int> tempB(B.begin(), B.end());
	tempA.resize(n);
	tempB.resize(n);
	Solve(n, tempA, tempB, result);
}

int k, q, curlen, idx = 0;
int a[N], f[N];
vector<int> poly(N, 0);

vector<int> poly_expo(vector<int> &p, int n){
	vector<int> res = p;
	n--;
	while(n>0){
		if(n & 1){
			vector<int> temp;
			do_FFT(res, p, temp);
			res = temp;
		}
		vector<int> temp;
		do_FFT(p, p, temp);
		p = temp;
		n >>= 1;
	}
	return res;
}

int n;

int32_t main(){
sp;
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		f[a[i]]++;
	}
	for(int i = 1; i < N; i++)
		if(f[i])
			poly[i] = 1;
	vector<int> ans = poly_expo(poly, k);
	for(int i = 0; i < ans.size(); i++)
		if(ans[i] > 0 && i > 0)
			cout<<i<<" ";
	return 0;
}
