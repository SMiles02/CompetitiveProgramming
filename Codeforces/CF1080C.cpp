#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll w(ll x, ll y)
{
    return (x*y)/2+min(x%2,y%2);
}

ll W(ll a, ll b, ll c, ll d)
{
    return w(c,d)-w(a-1,d)-w(c,b-1)+w(a-1,b-1);
}

ll B(ll a, ll b, ll c, ll d)
{
    return (c-a+1)*(d-b+1)-W(a,b,c,d);
}

void solve()
{
    ll n,m,x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>n>>m;
    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;
    ll whites=w(n,m),blacks;
    blacks=n*m-whites;
    //cout<<whites<<" "<<blacks<<"!!\n";
    whites+=B(x1,y1,x2,y2);
    blacks-=B(x1,y1,x2,y2);
    //cout<<whites<<" "<<blacks<<"!!\n";
    blacks+=W(x3,y3,x4,y4);
    whites-=W(x3,y3,x4,y4);
    //cout<<whites<<" "<<blacks<<"!!\n";
    int x5=max(x1,x3),y5=max(y1,y3),x6=min(x2,x4),y6=min(y2,y4);
    if (x5<=x6&&y5<=y6)
    {
        whites-=B(x5,y5,x6,y6);
        blacks+=B(x5,y5,x6,y6);
    }
    cout<<whites<<" "<<blacks<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}