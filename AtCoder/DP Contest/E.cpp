#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const ll INF = 1e18L + 5;
ll values[100001];

ll min(ll a, ll b)
{
    if (a<b) return a;
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=0;i<100001;++i)
    {
        values[i]=INF;
    }
    int n,w,a,b;
    cin>>n>>w;
    values[0]=0;
    while (n--)
    {
        cin>>a>>b;
        for (int i=100000;i-b>=0;--i)
        {
            values[i]=min(values[i],values[i-b]+a);
        }
    }
    for (int i=100000;i+1;--i)
    {
        if (values[i]<=w)
        {
            cout<<i;
            return 0;
        }
    }
    return 0;
}