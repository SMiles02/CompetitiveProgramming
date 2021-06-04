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
    int n,t=1;
    cin>>n;
    int a[n+1];
    bool ok;
    vector<int> ans;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    while (1)
    {
        while (a[n]==n)
            --n;
        if (n<4)
            break;
        ok=0;
        if (t&1)
        {
            for (int i=1;i<n;i+=2)
                if (a[i]==n)
                {
                    swap(a[i],a[i+1]);
                    ans.push_back(i);
                    ok=1;
                    break;
                }
            if (!ok)
            {
                swap(a[1],a[2]);
                ans.push_back(1);
            }
        }
        else
        {
            for (int i=2;i<n;i+=2)
                if (a[i]==n)
                {
                    swap(a[i],a[i+1]);
                    ans.push_back(i);
                    ok=1;
                    break;
                }
            if (!ok)
            {
                swap(a[2],a[3]);
                ans.push_back(2);
            }
        }
        ++t;
    }
    while (1)
    {
        ok=1;
        for (int i=1;i<=n;++i)
            if (a[i]!=i)
                ok=0;
        if (ok)
            break;
        if (t&1)
        {
            ans.push_back(1);
            swap(a[1],a[2]);
        }
        else
        {
            ans.push_back(2);
            swap(a[2],a[3]);
        }
        ++t;
    }
    cout<<sz(ans)<<"\n";
    for (int i : ans)
        cout<<i<<" ";
    cout<<"\n";
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