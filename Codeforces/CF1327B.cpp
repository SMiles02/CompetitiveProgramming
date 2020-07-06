#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,k,x,done,princess=0;
    map<int,int> princes;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        done=0;
        for (int j=0;j<k;++j)
        {
            cin>>x;
            if (!done&&!princes[x])
            {
                done=1;
                princes[x]=1;
            }
        }
        if (!done)
        {
            princess=i;
        }
    }
    if (!princess)
    {
        cout<<"OPTIMAL\n";
        return;
    }
    for (int i=1;i<=n;++i)
    {
        if (!princes[i])
        {
            cout<<"IMPROVE\n"<<princess<<" "<<i<<"\n";
            return;
        }
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