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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    cout<<15+7*(n-1)<<"\n";
    for (int i=0;i<1;++i)
    {
        cout<<10*i<<" 1\n";
        cout<<10*i<<" 2\n";
        cout<<10*i<<" 0\n";
        cout<<10*i-1<<" 1\n";
        cout<<10*i+1<<" 1\n";
        cout<<10*i<<" -1\n";
        cout<<10*i+1<<" -1\n";
        cout<<10*i+2<<" -1\n";
        cout<<10*i+2<<" 0\n";
        cout<<10*i+2<<" 1\n";
        cout<<10*i-2<<" 1\n";
        cout<<10*i-2<<" 2\n";
        cout<<10*i-2<<" 3\n";
        cout<<10*i-1<<" 3\n";
        cout<<10*i<<" 3\n";
    }
    for (int i=1;i<n;++i)
    {
        if (i&1)
        {
            cout<<2*i<<" 2\n";
            cout<<2*i<<" 3\n";
            cout<<2*i+1<<" 3\n";
            cout<<2*i+2<<" 3\n";
            cout<<2*i+2<<" 2\n";
            cout<<2*i+2<<" 1\n";
            cout<<2*i+1<<" 1\n";
        }
        else
        {
            cout<<2*i<<" 0\n";
            cout<<2*i<<" -1\n";
            cout<<2*i+1<<" -1\n";
            cout<<2*i+2<<" -1\n";
            cout<<2*i+2<<" 0\n";
            cout<<2*i+2<<" 1\n";
            cout<<2*i+1<<" 1\n";
        }
    }
    return 0;
}