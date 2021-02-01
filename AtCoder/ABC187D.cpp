#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,a,b,ans=0,A=0,B=0;
    cin>>n;
    vector<ll> v;
    while (n--)
    {
        cin>>a>>b;
        A+=a;
        v.push_back(2*a+b);
    }
    sort(v.begin(), v.end());
    while (A>=B)
    {
        ++ans;
        B+=v.back();
        v.pop_back();
    }
    cout<<ans;
    return 0;
}