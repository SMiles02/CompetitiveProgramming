#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
 
double pi=3.14159265358979;
 
double max(double a, double b)
{
    if (a>b)
        return a;
    return b;
}

void solve()
{
    int n;
    cin>>n;
    double x=1,y=2,a=1,b=2;
    y*=tan(pi/(2*n));
    b*=sin(pi/(2*n));
    x/=y;
    a/=b;
    cout<<fixed<<setprecision(10)<<max(x,a)*2<<"\n";
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