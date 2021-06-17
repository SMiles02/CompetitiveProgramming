#include <bits/stdc++.h>
using namespace std;

const int N = 6e5+69, mod=1e9+7;
int a[N], pt[N], rk[N];
 
int find_set(int v) {
    if (v == pt[v])
        return v;
    return pt[v] = find_set(pt[v]);
}
 
void make_set(int v) {
    for (int i=1;i<=v;++i)
    {
        pt[i] = i;
        rk[i] = 1;
    }
}
 
void unite(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap(a, b);
        pt[b] = a;
        rk[a] += rk[b];
    }
}

void solve()
{
    int n,k,ans=1;
    cin>>n;
    make_set(n);
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        a[k]=i;
    }
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        unite(i,a[k]);
    }
    for (int i=1;i<=n;++i)
        if (pt[i]==i)
        {
            ans*=2;
            while (ans>=mod)
                ans-=mod;
        }
    cout<<ans<<"\n";
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