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

int done[2000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    bool b;
    cin>>n>>m;
    string s[n];
    for (int i=0;i<n;++i)
        cin>>s[i];
    for (int i=0;i<n;++i)
    {
        b=0;
        for (int j=0;j<m;++j)
            if (s[i][j]=='1')
                ++done[j];
    }
    for (int i=n-1;i>=0;--i)
    {
        b=1;
        for (int j=0;j<m;++j)
            if (s[i][j]=='1'&&done[j]==1)
                b=0;
        if (b)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}