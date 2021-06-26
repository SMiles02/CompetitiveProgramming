#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll min(ll a, ll b)
{
    if (a<b)
    {
        return a;
    }
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,k,s,cur=1;
    cin>>n>>k>>s;
    if ((n-1)*k<s||k>s)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    for (int i=0;i<k;++i)
    {
        if (i%2)
        {
            cout<<cur-(s/(k-i))-min(1,s%(k-i));
            cur-=((s/(k-i))+min(1,s%(k-i)));
            s-=((s/(k-i))+min(1,s%(k-i)));
        }
        else
        {
            cout<<cur+(s/(k-i))+min(1,s%(k-i));
            cur+=(s/(k-i))+min(1,s%(k-i));
            s-=((s/(k-i))+min(1,s%(k-i)));
        }
        cout<<" ";
    }
    return 0;
}