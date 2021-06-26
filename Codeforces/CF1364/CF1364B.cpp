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
    int n,k;
    cin>>n;
    vector<int> v;
    cin>>k;
    v.push_back(k);
    for (int i=1;i<n;++i)
    {
        cin>>k;
        if (sz(v)>1&&((v[sz(v)-2]<v.back()&&v.back()<k)||(v[sz(v)-2]>v.back()&&v.back()>k)))
        {
            v.pop_back();
            v.push_back(k);
        }
        else
            v.push_back(k);
    }
    cout<<sz(v)<<"\n";
    for (int i : v)
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