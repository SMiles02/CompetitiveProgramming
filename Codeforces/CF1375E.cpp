#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
        return res * a;
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

vector<int> bigger[1000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    vector<pair<int,int>> swaps;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        for (int j=0;j<i;++j)
            if (a[i]>a[j])
                bigger[i].push_back(j);
    }
    vector<pair<int,int>> v;
    for (int i=n-1;i+1;--i)
    {
        for (int j : bigger[i])
            v.push_back({a[j],j});
        sort(v.begin(), v.end());
        for (auto j : v)
        {
            swaps.push_back({j.second+1,i+1});
            swap(a[i],a[j.second]);
        }
        v.clear();
    }
    cout<<sz(swaps)<<"\n";
    for (auto i : swaps)
        cout<<i.first<<" "<<i.second<<"\n";
    for (int i=0;i<n-1;++i)
        if (a[i]>a[i+1])
        {
            cout<<-1;
            return 0;
        }

    return 0;
}