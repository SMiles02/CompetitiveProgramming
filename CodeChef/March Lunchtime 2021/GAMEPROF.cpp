#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define tp array<int,3>
using namespace std;

bool cmp(tp &a, tp &b)
{
    return a[1]<b[1];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    ll k,c,ans=0;
    cin>>n>>k;
    vector<int> v(n);
    vector<tp> a(n);
    for (int i=0;i<n;++i)
    {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        v[i]=a[i][0];
    }
    sort(a.begin(), a.end(), cmp);
    for (int i : v)
    {
        c=0;
        for (auto j : a)
            if (i<=j[0])
            {
                c+=j[2];
                ans=max(ans,c-k*(j[1]-i));
            }
    }
    cout<<ans;
    return 0;
}