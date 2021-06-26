#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y;
    ll ans=0;
    cin>>n;
    map<int,ll> numberOfX;
    map<int,ll> numberOfY;
    map<pair<int,int>,ll> alreadyThere;
    while (n--)
    {
        cin>>x>>y;
        ans+=numberOfX[x]+numberOfY[y]-alreadyThere[{x,y}];
        ++numberOfX[x];
        ++numberOfY[y];
        ++alreadyThere[{x,y}];
    }
    cout<<ans;
    return 0;
}