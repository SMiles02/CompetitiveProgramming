#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

void solve()
{
    ll m,d,w,l,r,n,c,e;
    cin>>m>>d>>w;
    e=gcd(d-1,w);
    w/=e;
    l=w;r=(min(m,d)/w)*w;
    //cout<<"(y-x)("<<d/e<<") = 0 (mod "<<w<<")\n";
    if (l>r)
        cout<<"0\n";
    else
    {
        n=(r-l)/w+1;
        c=(min(m,d)-(2*w))-(min(m,d)-w);
        cout<<(((2*(min(m,d)-w)+(n-1)*(c)))*n)/2<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}