#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,x,k;
    cin>>n>>x;
    map<int,int> m;
    while (n--)
    {
        cin>>k;
        m[k]=1;
    }
    k=1;
    while (1)
    {
        if (!(m[k]))
        {
            if (x)
            {
                --x;
            }
            else
            {
                cout<<k-1<<"\n";
                return;
            }
        }
        ++k;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}