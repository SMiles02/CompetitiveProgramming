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

int ans[61][2];

void solve()
{
    int n,m,x;
    cin>>n>>m;
    for (int i=0;i<61;++i)
    {
        ans[i][0]=0;
        ans[i][1]=0;
    }
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
        {
            cin>>x;
            ++ans[i+j][x];
        }
    x=0;
    for (int i=0;i<=(n+m-2)/2;++i)
        if (2*i!=(n+m-2))
            x+=(min(ans[i][0]+ans[n+m-2-i][0],ans[i][1]+ans[n+m-2-i][1]));
    cout<<x<<"\n";
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