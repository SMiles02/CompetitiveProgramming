#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    int a[m][2],ans[m][2];
    vector<array<int,2>> good,bad;
    for (int i=0;i<m;++i)
    {
        cin>>a[i][0]>>a[i][1];
        if (a[i][1])
            good.push_back({a[i][0],i});
        else
            bad.push_back({a[i][0],i});
    }
    if (n==2)
    {
        cout<<"1 2";
        return 0;
    }
    sort(good.begin(), good.end());
    sort(bad.rbegin(), bad.rend());
    for (int i=0;i<n-1;++i)
    {
        ans[good[i][1]][0]=1;
        ans[good[i][1]][1]=i+2;
    }
    for (int i=0;i<m&&!bad.empty();++i)
        for (int j=0;j<i&&!bad.empty();++j)
        {
            if (bad.back()[0]<good[i][0])
            {
                cout<<-1;
                return 0;
            }
            ans[bad.back()[1]][0]=i+2;
            ans[bad.back()[1]][1]=j+2;
            bad.pop_back();
        }
    for (int i=0;i<m;++i)
        cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
    return 0;
}