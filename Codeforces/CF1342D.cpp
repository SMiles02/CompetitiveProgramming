#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5+6;
int f[N], p[N], c[N], a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,ans=1;
    cin>>n>>k;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        ++f[a[i]];
    }
    for (int i=1;i<=k;++i)
        cin>>c[i];
    for (int i=k;i>0;--i)
    {
        p[i]=p[i+1]+f[i];
        ans=max(ans,(p[i]+c[i]-1)/c[i]);
    }
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> pq;
    vector<vector<int>> print(ans);
    for (int i=0;i<ans;++i)
        pq.push({0,i});
    sort(a,a+n);
    array<int,2> b;
    for (int i=0;i<n;++i)
    {
        b=pq.top();
        pq.pop();
        print[b[1]].push_back(a[i]);
        ++b[0];
        pq.push(b);
    }
    cout<<ans<<"\n";
    for (auto i : print)
    {
        cout<<i.size()<<" ";
        for (int j : i)
            cout<<j<<" ";
        cout<<"\n";
    }
    return 0;
}