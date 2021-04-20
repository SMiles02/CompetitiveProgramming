#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool cmp(array<int,2> &a, array<int,2> &b)
{
    return a[1]<b[1];
}

int calc(multiset<int> &m)
{
    if (m.empty())
        return 0;
    return *(--m.end())-*(m.begin());
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    int n;
    cin>>n;
    vector<array<int,2>> a(n);
    vector<ll> v;
    for (int i=0;i<n;++i)
        for (int j=0;j<2;++j)
            cin>>a[i][j];
    sort(a.begin(), a.end());
    multiset<int> x1,y1,x2,y2;
    for (int i=0;i<n;++i)
    {
        x2.insert(a[i][0]);
        y2.insert(a[i][1]);
    }
    for (int i=0;i<n;++i)
    {
        x2.erase(x2.lower_bound(a[i][0]));
        y2.erase(y2.lower_bound(a[i][1]));
        x1.insert(a[i][0]);
        y1.insert(a[i][1]);
        v.push_back(1LL*calc(x1)*calc(y1)+1LL*calc(x2)*calc(y2));
    }
    sort(a.begin(), a.end(), cmp);
    x1.clear();
    y1.clear();
    x2.clear();
    y2.clear();
    for (int i=0;i<n;++i)
    {
        x2.insert(a[i][0]);
        y2.insert(a[i][1]);
    }
    for (int i=0;i<n;++i)
    {
        x2.erase(x2.lower_bound(a[i][0]));
        y2.erase(y2.lower_bound(a[i][1]));
        x1.insert(a[i][0]);
        y1.insert(a[i][1]);
        v.push_back(1LL*calc(x1)*calc(y1)+1LL*calc(x2)*calc(y2));
    }
    sort(v.begin(), v.end());
    cout<<v.back()-v[0];
    return 0;
}