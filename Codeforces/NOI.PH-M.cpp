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
    int n,m,k,s;
    ll ans=0;
    map<int,int> pile;
    vector<int> v;
    vector<int> w;
    cin>>n;
    s=n;
    while (n--)
    {
        cin>>k;
        v.push_back(k);
    }
    cin>>m;
    s+=m;
    while (m--)
    {
        cin>>k;
        w.push_back(k);
        pile[k]=1;
    }
    for (int i=1;i<=s;++i)
    {
        if (pile[i])
        {
            while (w.back()!=i)
            {
                ++ans;
                v.push_back(w.back());
                w.pop_back();
            }
            w.pop_back();
        }
        else
        {
            while (v.back()!=i)
            {
                ++ans;
                w.push_back(v.back());
                v.pop_back();
            }
            v.pop_back();
        }
    }
    cout<<ans;
    return 0;
}