#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,x,y=0;
    cin>>n;
    int freq[n+1];
    for (int i=1;i<=n;++i)
        freq[i]=0;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        ++freq[x];
    }
    x=0;
    for (int i=1;i<=n;++i)
    {
        if (freq[i]>x)
        {
            x=freq[i];
            y=1;
        }
        else if (x==freq[i])
            ++y;
    }
    cout<<(n-y)/(x-1)-1<<"\n";
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