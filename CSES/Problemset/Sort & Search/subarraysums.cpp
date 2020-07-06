#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,k;
    ll p=0,ans=0;
    map<ll,int> m;
    cin>>n>>x;
    while (n--)
    {
        ++m[p];
        cin>>k;
        p+=k;
        ans+=m[p-x];
    }
    cout<<ans;
    return 0;
}