#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

int buckets[101][101];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,cur=0,x=1e9;
    ll k,g,a,b;
    double d;
    map<int,int> m;
    for (int i=1;i<31623;++i)
        if (x%i==0)
        {
            ++cur;
            m[i]=cur;
            ++cur;
            m[x/i]=cur;
        }
    cin>>n;
    while (n--)
    {
        cin>>d;
        d*=x;
        k=d;
        g=gcd(x,k);
        a=k/g;
        b=x/g;
    }
    return 0;
}