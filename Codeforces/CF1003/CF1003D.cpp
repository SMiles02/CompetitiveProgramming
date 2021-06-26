#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int powers[31];
map<int,int> occurences;

void solve()
{
    int cur,ans=0;
    cin>>cur;
    for (int i=30;i+1;--i)
    {
        ans+=min(occurences[powers[i]],cur/powers[i]);
        cur-=(min(occurences[powers[i]],cur/powers[i])*powers[i]);
    }
    if (cur==0) cout<<ans;
    else cout<<-1;
    cout<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,k;
    cin>>n>>q;
    powers[0]=1;
    for (int i=1;i<31;++i)
        powers[i]=2*powers[i-1];
    for (int i=0;i<n;++i)
    {
        cin>>k;
        ++occurences[k];
    }
    while (q--)
        solve();
    return 0;
}