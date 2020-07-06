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
    int n,a,b,c,ans;
    cin>>n;
    while (n--)
    {
        cin>>a>>b>>c;
        ans=0;
        if (c>b)
        {
            swap(c,b);
        }
        if (b>a)
        {
            swap(a,b);
        }
        if (c>b)
        {
            swap(c,b);
        }
        if (a>0)
        {
            --a;
            ++ans;
        }
        if (b>0)
        {
            --b;
            ++ans;
        }
        if (c>0)
        {
            --c;
            ++ans;
        }
        if (a>0&&b>0)
        {
            --a;
            --b;
            ++ans;
        }
        if (a>0&&c>0)
        {
            --a;
            --c;
            ++ans;
        }
        if (b>0&&c>0)
        {
            --b;
            --c;
            ++ans;
        }
        if (a>0&&b>0&&c>0)
        {
            --a;
            --b;
            --c;
            ++ans;
        }
        cout<<ans<<"\n";
    }
    return 0;
}