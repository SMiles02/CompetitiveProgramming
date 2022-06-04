#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
        return res * a;
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

int n,cur,smol,pos;
int a[100];

void solve()
{
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i];
    cur=0;
    while (cur<n)
    {
        smol=a[cur];
        for (int i=cur+1;i<n;++i)
            if (a[i]<smol)
            {
                smol=a[i];
                pos=i;
            }
        if (smol==a[cur])
        {
            ++cur;
            continue;
        }
        for (int i=pos;i>cur;--i)
            swap(a[i],a[i-1]);
        cur=pos;
    }
    for (int i=0;i<n;++i)
        cout<<a[i]<<" ";
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