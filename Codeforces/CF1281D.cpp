#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int r,c;
vector<int> x;
vector<int> y;

void solve()
{
    x.clear();
    y.clear();
    cin>>r>>c;
    string a[r];
    for (int i=0;i<r;++i)
    {
        cin>>a[i];
        for (int j=0;j<c;++j)
        {
            if (a[i][j]=='P')
            {
                x.push_back(i);
                y.push_back(j);
            }
        }
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    if (sz(x)==0)
    {
        cout<<"0\n";
        return;
    }
    if (sz(x)==r*c)
    {
        cout<<"MORTAL\n";
        return;
    }
    cout<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}