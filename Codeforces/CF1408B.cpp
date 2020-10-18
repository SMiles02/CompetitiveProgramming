#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,k,x;
    cin>>n>>k;
    set<int> s;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        s.insert(x);
    }
    if (k==1&&sz(s)>1)
        cout<<"-1\n";
    else if (k>=sz(s))
        cout<<"1\n";
    else
        cout<<1+(sz(s)-2)/(k-1)<<"\n";
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