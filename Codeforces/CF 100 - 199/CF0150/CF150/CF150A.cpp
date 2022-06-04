#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,k,s;
    cin>>n;
    k=n;
    vector<ll> v;
    if (n==1)
    {
        cout<<"1\n0";
        return 0;
    }
    while (!(k%2))
    {
        k/=2;
        v.push_back(2);
    }
    for (int i=3;i<=sqrt(k);i+=2)
    {
        while (!(k%i))
        {
            k/=i;
            v.push_back(i);
        }
    }
    if (k!=1)
    {
        v.push_back(k);
    }
    if (sz(v)==1)
    {
        cout<<"1\n0";
        return 0;
    }
    if (sz(v)==2)
    {
        cout<<2;
        return 0;
    }
    cout<<"1\n"<<v[0]*v[1];
    return 0;
}