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

void solve()
{
    int n,x=0,y;
    cin>>n;
    y=n-1;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    vector<int> v;
    for (int i=0;i<n;++i)
    {
        if (i%2)
        {
            v.push_back(a[x]);
            ++x;
        }
        else
        {
            v.push_back(a[y]);
            --y;
        }
    }
    for (int i=0;i<n;++i)
    {
        cout<<v.back()<<" ";
        v.pop_back();
    }
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}