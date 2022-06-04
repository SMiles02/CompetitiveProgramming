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

void solve()
{
    int n,m;
    ll ans=0;
    cin>>n>>m;
    int p[n+4][m+4];
    string s[n+4];
    bitset<504> dp[m+4][n+4];
    for (int i=0;i<=n;++i)
        p[i][0]=0;
    for (int i=1;i<=n;++i)
    {
        cin>>s[i];
        for (int j=0;j<m;++j)
        {
            if (s[i][j]=='*')
            {
                ++ans;
                dp[1][i][j+1]=1;
                p[i][j+1]=p[i][j]+1;
            }
            else
                p[i][j+1]=p[i][j];
            //cout<<p[i][j+1]<<" ";
        }
        //cout<<"\n";
    }
    for (int k=3;k<=m;k+=2)
        for (int i=1;i<=n;++i)
            for (int j=1;j+k-1<=m;++j)
            {
                if (dp[k-2][i-1][j+1])
                    if (p[i][j+k-1]-p[i][j-1]==k)
                    {
                        //cout<<k<<" "<<i<<" "<<j<<"\n";
                        ++ans;
                        dp[k][i][j]=1;
                    }
            }
    cout<<ans<<"\n";
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