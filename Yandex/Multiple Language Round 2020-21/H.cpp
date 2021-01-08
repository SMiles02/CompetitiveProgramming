#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

string to_upper(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

const int mn = 1001;
int dp[101][mn];
bitset<101> ans;
//i, sum

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,s,x=-1,l=0;
    cin>>n>>s;
    int a[n+1];
    a[0]=0;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        for (int j=0;j<mn;++j)
            dp[i][j]=dp[i-1][j];
        for (int k=0;k<i;++k)
            if (a[k]<=a[i])
                for (int j=a[i];j<mn;++j)
                    dp[i][j]=max(dp[i][j],dp[k][j-a[i]]+1);
        if (dp[i][s]>x)
        {
            x=dp[i][s];
            l=i;
        }
    }
    cout<<x<<"\n";
    if (x==0)
    {
        while (n--)
            cout<<"0 ";
        return 0;
    }
    ans[l]=1;
    for (int i=l-1;i>=0;--i)
        if (a[i]<=a[l])
            if (dp[l][s]-1==dp[i][s-a[l]])
            {
                ans[i]=1;
                s-=a[l];
                l=i;
            }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    return 0;
}