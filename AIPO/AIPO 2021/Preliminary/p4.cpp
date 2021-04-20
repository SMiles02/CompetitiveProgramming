#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define ll long long
using namespace std;

bool isPalindrome(ll n)
{
    vector<int> v;
    while (n)
    {
        v.push_back(n%10);
        n/=10;
    }
    for (int i=0;i<sz(v);++i)
        if (v[i]!=v[sz(v)-1-i])
            return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,ans=-1;
    cin>>n;
    for (ll i=2;i*i<=n;++i)
        if (n%i==0)
        {
            if (isPalindrome(i))
                ans=i;
            while (n%i==0)
                n/=i;
        }
    if (n>1&&isPalindrome(n))
        ans=n;
    cout<<ans;
    return 0;
}