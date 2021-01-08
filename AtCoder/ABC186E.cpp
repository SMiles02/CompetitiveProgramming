#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
using namespace std;

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void solve() 
{ 
    int n,s,k,x0,y0,g,l=-1e9,r=1e9,m;
    cin>>n>>s>>k;
    k=n-k;
    if (!find_any_solution(k,-n,s,x0,y0,g))
    {
        cout<<"-1\n";
        return;
    }
    //cout<<g<<"\n";
    //cout<<x0<<" "<<y0<<"\n";
    while (l<r)
    {
        m=l+(r-l)/2+1;
        //cout<<l<<" "<<r<<" "<<m<<"\n";
        if (x0+m*((-n)/g)>=0)
            l=m;
        else
            r=m-1;
    }
    cout<<x0+l*((-n)/g)<<"\n";
} 

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}