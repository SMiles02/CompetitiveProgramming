#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 100;
vector<int> edges[mn];

void solve()
{
    int n,k,x;
    cin>>n>>k;
    int a[n][2];
    for (int i=0;i<n;++i)
        cin>>a[i][0]>>a[i][1];
    for (int i=0;i<n;++i)
    {
        x=0;
        for (int j=0;j<n;++j)
            if (abs(a[i][0]-a[j][0])+abs(a[i][1]-a[j][1])<=k)
                ++x;
        if (x==n)
        {
            cout<<"1\n";
            return;
        }
    }
    cout<<"-1\n";
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