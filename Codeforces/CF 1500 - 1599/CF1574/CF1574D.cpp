#include <bits/stdc++.h>
#define ll long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 10, M = 1e5+1, MOD = 1e9+7;
int n,a[N][M],b1,b2,mx;
vector<int> ans;
set<ll> s;

int RNG(int x, int y)
{
    return uniform_int_distribution<int>(x,y)(rng);
}

int get_val(int base, vector<int>& v)
{
    ll rtn = 0;
    for (int i : v)
    {
        rtn*=base;
        rtn+=i;
        rtn%=MOD;
    }
    return rtn;
}

ll hash_val(vector<int>& v)
{
    return 1LL*MOD*get_val(b1,v)+get_val(b2,v);
}

void check(vector<int>& v)
{
    if (s.count(hash_val(v)))
        return;
    int cur=0;
    for (int i=0;i<n;++i)
        cur+=a[i][v[i]];
    if (cur>mx)
    {
        mx=cur;
        ans=v;
    }
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m;
    cin>>n;
    b1=RNG(1e5+1,1e6);
    b2=RNG(1e5+1,1e6);
    for (int i=0;i<n;++i)
    {
        cin>>a[i][0];
        for (int j=1;j<=a[i][0];++j)
            cin>>a[i][j];
    }
    ans.resize(n);
    cin>>m;
    vector<int> w(n);
    vector<vector<int>> v(m,vector<int>(n));
    for (int i=0;i<m;++i)
    {
        for (int &j : v[i])
            cin>>j;
        s.insert(hash_val(v[i]));
    }
    for (int i=0;i<m;++i)
        for (int j=0;j<n;++j)
            if (v[i][j]>1)
            {
                --v[i][j];
                check(v[i]);
                ++v[i][j];
            }
    for (int i=0;i<n;++i)
        w[i]=a[i][0];
    check(w);
    for (int i : ans)
        cout<<i<<" ";
    return 0;
}