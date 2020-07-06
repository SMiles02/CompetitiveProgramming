#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,pointer=0,ans=0;
    cin>>n>>m>>k;
    int a[n];
    int b[m];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for (int i=0;i<m;++i)
    {
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+m);
    for (int i=0;i<n;++i)
    {
        while (a[i]-k>b[pointer])
        {
            ++pointer;
            if (pointer==m)
            {
                cout<<ans;
                return 0;
            }
        }
        if (abs(a[i]-b[pointer])<=k)
        {
            ++ans;
            ++pointer;
            if (pointer==m)
            {
                cout<<ans;
                return 0;
            }
        }
    }
    cout<<ans;
    return 0;
}