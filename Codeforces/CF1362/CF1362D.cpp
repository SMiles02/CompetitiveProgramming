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

int maxDone[500001];
int numDone[500001];
vector<int> edges[500001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,a,b;
    cin>>n>>m;
    vector<int> v;
    for (int i=0;i<m;++i)
    {
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<pair<int,int>> p;
    for (int i=1;i<=n;++i)
    {
        cin>>b;
        p.push_back({b,i});
    }
    sort(p.begin(), p.end());
    for (auto x : p)
    {
        a=x.first;b=x.second;
        v.push_back(b);
        if (numDone[b]!=a-1||maxDone[b]!=a-1)
        {
            cout<<-1;
            return 0;
        }
        for (int k : edges[b])
            if (a>maxDone[k])
            {
                maxDone[k]=a;
                ++numDone[k];
            }
    }
    for (int i : v)
        cout<<i<<" ";
    return 0;
}