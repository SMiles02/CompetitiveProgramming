#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll binpow(ll a, ll b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
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

void solve()
{
    int n,last=0,x,y,l,r,m,alice=0,bob=0,ans;
    cin>>n;
    int dp[n+1];
    dp[n+1]=0;
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        dp[i]=dp[i-1]+x;
    }
    x=1;y=n;
    for (int turn=1;turn;++turn)
    {
        if (x>y)
        {
            ans=turn-1;
            break;
        }
        if (dp[y]-dp[x-1]<=last)
        {
            if (turn%2)
                alice+=dp[y]-dp[x-1];
            else
                bob+=dp[y]-dp[x-1];
            ans=turn;
            break;
        }
        if (turn%2)
        {
            l=x;r=y;
            while (l<r)
            {
                m=l+(r-l)/2;
                if (dp[m]-dp[x-1]>last)
                {
                    r=m;
                }
                else
                {
                    l=m+1;
                }
            }
            m=l;
            alice+=dp[m]-dp[x-1];
            last=dp[m]-dp[x-1];
            x=m+1;
        }
        else
        {
            l=x;r=y;
            while (l<r)
            {
                m=l+(r-l)/2+1;
                if (dp[y]-dp[m-1]>last)
                {
                    l=m;
                }
                else
                {
                    r=m-1;
                }
            }
            m=l;
            bob+=dp[y]-dp[m-1];
            last=dp[y]-dp[m-1];
            y=m-1;
        }
    }
    cout<<ans<<" "<<alice<<" "<<bob<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}