#include <bits/stdc++.h>
using namespace std;

string s;

bool ok(vector<int> v)
{
    int c = 0;
    for (auto i : s)
    {
        c+=v[i-'A'];
        if (c<0)
            return 0;
    }
    if (c==0)
        return 1;
    return 0;
}

void solve()
{
    cin>>s;
    for (int i=-1;i<2;i+=2)
        for (int j=-1;j<2;j+=2)
            for (int k=-1;k<2;k+=2)
                if (ok({i,j,k}))
                {
                    cout<<"YES\n";
                    return;
                }
    cout<<"NO\n";
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