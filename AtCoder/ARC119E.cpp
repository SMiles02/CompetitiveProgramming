#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int M = 1e4;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    ll og=0, ans;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=1;i<n;++i)
        og+=abs(a[i]-a[i-1]);
    ans=og;
    vector<array<int,2>> v(n-1),w(min(M*5,n-1));
    for (int i=1;i<n;++i)
    {
        v[i-1]={abs(a[i]-a[i-1]),i-1};
        ans=min({ans,og-abs(a[i]-a[i-1])+abs(a[i]-a[0]),og-abs(a[i]-a[i-1])+abs(a[n-1]-a[i-1])});
    }
    sort(v.rbegin(), v.rend());
    for (int i=0;i<min(n-1,M*3);++i)
        w[i]={v[i][1],v[i][0]};
    for (int i=n-2,j=min(n-1,M*3);i>=min(n-1,M*3)&&j<M*2;--i,++j)
        w[j]={v[i][1],v[i][0]};
    sort(w.begin(), w.end());
    for (int i=0;i<min(n-1,M*5);++i)
        for (int j=0;j<i;++j)
            ans=min(ans,og-w[i][1]-w[j][1]+abs(a[w[i][0]]-a[w[j][0]])+abs(a[w[i][0]+1]-a[w[j][0]+1]));
    cout<<ans;
    return 0;
}