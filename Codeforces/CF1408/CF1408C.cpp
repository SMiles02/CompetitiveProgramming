#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

double div(double a, double b)
{
    return a/b;
}

double div(double a, int b)
{
    return a/b;
}

void solve()
{
    int n,l;
    cin>>n>>l;
    double ans=0,x=0,y=l,d,e;
    int a[n],b=0,c=n-1,vX=1,vY=1;
    for (int i=0;i<n;++i)
        cin>>a[i];
    while (b<=c)
    {
        d=div(-x+a[b],vX);
        e=div(y-a[c],vY);
        if (d<e)
        {
            x=a[b];
            y-=(d*vY);
            ++b;
            ++vX;
            ans+=d;
        }
        else if (d>e)
        {
            x+=(e*vX);
            y=a[c];
            --c;
            ++vY;
            ans+=e;
        }
        else
        {
            x=a[b];
            y=a[c];
            ++b;
            --c;
            ++vX;
            ++vY;
            ans+=d;
        }
    }
    cout<<fixed<<setprecision(10)<<(ans+div(y-x,vX+vY))<<"\n";
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