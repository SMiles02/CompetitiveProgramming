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
    int n,k;
    cin>>n;
    string s;
    vector<string> v;
    vector<string> w;
    map<string,int> m;
    for (int i=0;i<n;++i)
    {
        cin>>s;
        if (!m[s])
        {
            v.push_back(s);
        }
        ++m[s];
    }
    w.push_back(v[0]);k=m[v[0]];
    for (int i=1;i<sz(v);++i)
    {
        if (m[v[i]]>k)
        {
            k=m[v[i]];
            w.clear();
            w.push_back(v[i]);
        }
        else if (m[v[i]]==k)
        {
            w.push_back(v[i]);
        }
    }
    sort(w.begin(), w.end());
    for (int i=0;i<sz(w);++i)
    {
        cout<<w[i]<<"\n";
    }
    return 0;
}