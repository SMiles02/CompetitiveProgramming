#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,c;
    map<int,vector<int>> m;
    cin>>n;
    for (int i=2;i<=n;++i)
    {
        cin>>k;
        m[k].push_back(i);
    }
    for (int i=1;i<n;++i)
    {
        if (sz(m[i]))
        {
            c=0;
            for (int j=0;j<sz(m[i]);++j)
            {
                if (!sz(m[m[i][j]]))
                {
                    ++c;
                }
            }
            if (c<3)
            {
                cout<<"No";
                return 0;
            }
        }
    }
    cout<<"Yes";
    return 0;
}