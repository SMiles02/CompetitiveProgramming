#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int a[50];

void solve()
{
    int n,mini=999;
    cin>>n;
    map<int,int> m;
    for (int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    for (int i=0;i+1<n;++i)
        mini=min(mini,a[i+1]-a[i]);
    cout<<mini<<"\n";
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