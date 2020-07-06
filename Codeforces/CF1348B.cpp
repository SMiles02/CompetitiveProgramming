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

int a[100];

void solve()
{
    int n,k;
    cin>>n>>k;
    set<int> s;
    vector<int> ideal;
    map<int,int> m;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        s.insert(a[i]);
        m[a[i]]=1;
    }
    if (sz(s)>k)
    {
        cout<<"-1\n";
        return;
    }
    for (int i=1;i<=n;++i)
    {
        if (!m[i]&&sz(s)<k)
        {
            s.insert(i);
            m[i]=1;
        }
        if (m[i]==1)
        {
            ideal.push_back(i);
            m[i]=2;
        }
    }
    cout<<(10000/k)*k<<"\n";
    for (int i=0;i<10000/k;++i)
    {
        for (int j=0;j<k;++j)
        {
            cout<<ideal[j]<<" ";
        }
    }
    ideal.clear();
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