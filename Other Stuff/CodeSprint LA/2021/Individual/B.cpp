#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 2069;
int pt[mn],rk[mn];
 
int find_set(int v) {
    if (v == pt[v])
        return v;
    return pt[v] = find_set(pt[v]);
}
 
void make_set(int v) {
    for (int i=0;i<=v;++i)
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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    make_set(n);
    vector<array<int,2>> a(n);
    for (int i=0;i<n;++i)
        for (int j=0;j<2;++j)
            cin>>a[i][j];
    vector<array<int,3>> v;
    for (int i=0;i<n;++i)
        for (int j=0;j<i;++j)
            v.push_back({abs(a[i][0]-a[j][0])+abs(a[i][1]-a[j][1]),j,i});
    sort(v.begin(), v.end());
    ll ans=0;
    for (auto i : v)
    {
        if (find_set(i[1])!=find_set(i[2]))
        {
            unite(i[1],i[2]);
            ans+=i[0];
        }
    }
    cout<<ans*2;
    return 0;
}