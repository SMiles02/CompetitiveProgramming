#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n;
    vector<int> p(n+2,0);
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        ++p[max(1,i-k+1)];
        --p[i+1];
    }
    for (int i=1;i<=n;++i)
    {
        p[i]+=p[i-1];
        cout<<min(1,p[i])<<" ";
    }
    cout<<"\n";
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