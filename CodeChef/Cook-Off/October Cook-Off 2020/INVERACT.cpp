#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int maxn=1e6+7;
int bit[maxn];

void update(int i)
{
    while (i<maxn)
    {
        ++bit[i];
        i+=(i&-i);
    }
}

int query(int i)
{
    int x=0;
    while (i)
    {
        x+=bit[i];
        i-=(i&-i);
    }
}

int r_query(int l, int r)
{
    return query(r) - query(l-1);
}

int a[101];

void solve()
{
    for (int i=0;i<maxn;++i)
        bit[i]=0;
    int n;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        
    }
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