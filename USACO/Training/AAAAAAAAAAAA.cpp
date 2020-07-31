#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m;
int a[100000];

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

bool check(ll k)
{
    int ans=1;
    ll cur=0;
    for (int i=0;i<n;++i)
    {
        cur+=a[i];
        if (cur>k)
        {
            ++ans;
            cur=a[i];
        }
    }
    if (ans>m)
        return 0;
    return 1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("verybest.in", "r", stdin);
    freopen("verybest.out", "w", stdout);
    cin >> n >> m;
    ll l=1,r=1e15,mid;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        l=max(l,a[i]);
    }
    while (l<r)
    {
        mid=l+(r-l)/2;
        //cout<<l<<" "<<r<<" "<<mid<<"\n";
        if (check(mid))
            r=mid;
        else
            l=mid+1;
    }
    cout<<l;
	return 0;
}