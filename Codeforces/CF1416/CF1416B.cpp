#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

void solve()
{
    vector<pair<pii,int>> ans;
    int n,k;
    ll tot=0;
    cin>>n;
    int a[n+1];
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        tot+=a[i];
    }
    if (tot%n)
    {
        cout<<"-1\n";
        return;
    }
    tot/=n;
    for (int i=2;i<=n;++i)
    {
        k=((i-(a[i]%i))%i);
        ans.push_back({{1,i},k});
        a[1]-=k;
        a[i]+=k;
        ans.push_back({{i,1},a[i]/i});
        a[1]+=a[i];
        a[i]=0;
    }
    for (int i=2;i<=n;++i)
        ans.push_back({{1,i},tot});
    cout<<sz(ans)<<"\n";
    for (auto i : ans)
        cout<<i.f.f<<" "<<i.f.s<<" "<<i.s<<"\n";
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