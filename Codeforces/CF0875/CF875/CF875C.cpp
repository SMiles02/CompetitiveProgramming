#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
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

const int mn = 1e5+69;
int d;
bitset<mn> cap;
vector<int> edges[mn];

int f(int k)
{
    if (cap[k])
        k-=mn;
    return k;
}

void dfs(int c)
{
    cap[c]=1;
    ++d;
    for (int i : edges[c])
        if (!cap[i])
            dfs(i);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,l;
    bool e=0;
    cin>>n>>m;
    vector<int> toDo;
    vector<vector<int>> v;
    for (int i=0;i<n;++i)
    {
        cin>>l;
        vector<int> w(l+1);
        w[0]=l;
        for (int j=1;j<=l;++j)
            cin>>w[j];
        v.push_back(w);
    }
    for (int i=0;i+1<n;++i)
    {
        e=1;
        for (int j=1;j<=min(v[i][0],v[i+1][0]);++j)
            if (v[i][j]!=v[i+1][j])
            {
                e=0;
                break;
            }
        if (e&&v[i][0]<=v[i+1][0])
            continue;
        if (e)
        {
            cout<<"No";
            return 0;
        }
        for (int j=1;1;++j)
            if (v[i][j]!=v[i+1][j])
            {
                if (v[i][j]<v[i+1][j])
                    edges[v[i+1][j]].push_back(v[i][j]);
                else
                    toDo.push_back(v[i][j]);
                break;
            }
    }
    for (int i : toDo)
        if (!cap[i])
            dfs(i);
    for (int i=0;i+1<n;++i)
        for (int j=1;j<=min(v[i][0],v[i+1][0]);++j)
            if (v[i][j]!=v[i+1][j])
            {
                if (f(v[i][j])>f(v[i+1][j]))
                {
                    cout<<"No";
                    return 0;
                }
                break;
            }
    cout<<"Yes\n"<<d<<"\n";
    for (int i=1;i<mn;++i)
        if (cap[i])
            cout<<i<<" ";
    return 0;
}