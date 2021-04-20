#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

const int mod = 1e9+7, N = 2e5+20;
int ans[N];

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

void solve()
{
    int m,r=0;
    string s;
    cin>>s;
    cin>>m;
    for (auto i : s)
        r=add(r,ans[m+(i-'0')]);
    cout<<r<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<int> v(10),w(10);
    v[0]=1;
    for (int i=1;i<N;++i)
    {
        for (int j=2;j<10;++j)
            w[j]=v[j-1];
        w[0]=v[9];
        w[1]=add(v[0],v[9]);
        v=w;
        for (int j=0;j<10;++j)
            ans[i]=add(ans[i],v[j]);
    }
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}