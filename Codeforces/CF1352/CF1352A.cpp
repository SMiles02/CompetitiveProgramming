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
    int n;
    cin>>n;
    vector<int> v;
    if (n==10000)
        v.push_back(10000);
    else if (n>=1000)
    {
        v.push_back(n-(n%1000));
        if ((n%1000)-(n%100)>0)
            v.push_back((n%1000)-(n%100));
        if ((n%100)-(n%10)>0)
            v.push_back((n%100)-(n%10));
        if (n%10>0)
            v.push_back(n%10);
    }
    else if (n>=100)
    {
        v.push_back(n-(n%100));
        if ((n%100)-(n%10)>0)
            v.push_back((n%100)-(n%10));
        if (n%10>0)
            v.push_back(n%10);
    }
    else if (n>=10)
    {
        v.push_back(n-(n%10));
        if (n%10>0)
            v.push_back(n%10);
    }
    else
        v.push_back(n);
    cout<<sz(v)<<"\n";
    for (auto i : v)
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