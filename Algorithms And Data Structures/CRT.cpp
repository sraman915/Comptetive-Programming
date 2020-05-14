#define ll long long int
void extended(ll a, ll b, ll& gcd, ll& x, ll& y)
{
        x=0, y=1;
        int u=1, v=0, m, n, q, r;
        gcd = b;
        while (a!=0) {
                q=gcd/a; r=gcd%a;
                m=x-u*q; n=y-v*q;
                gcd=a; a=r; x=u; y=v; u=m; v=n;
        }
}
int main()
{
    int n;
    cin>>n;
    ll A[n],B[n],mx=1,sm=0;
    for(int i=0;i<n;i++)
    {
            cin>>A[i]>>B[i];
            mx*=B[i];
    }
    for(int i=0;i<n;i++)
    {
            ll gcd, x, y;
            extended(mx/B[i],B[i],gcd,x,y);
            if(x<0) x+=B[i];
            sm=(sm+A[i]*(mx/B[i])*x);
    }
    cout<<sm%mx<<"\n";
    return 0;
}
