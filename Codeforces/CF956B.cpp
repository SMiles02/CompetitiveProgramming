#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

bool cmp(pii a, pii b)
{
    if (1LL*a.f*b.s<1LL*b.f*a.s)
        return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,u;
    cin>>n>>u;
    int a[n+1];
    for (int i=0;i<n;++i)
        cin>>a[i];
    a[n]=2e9+7;
    vector<pii> v;
    k=0;
    for (int i=0;i<n;++i)
    {
        while (a[k+1]<=a[i]+u)
            ++k;
        if (k-i<2)
            continue;
        v.push_back({a[k]-a[i+1],a[k]-a[i]});
    }
    sort(v.begin(), v.end(), cmp);
    if (v.empty())
    {
        cout<<-1;
        return 0;
    }
    cout<<fixed<<setprecision(10)<<((double)v.back().f/v.back().s);
    return 0;
}