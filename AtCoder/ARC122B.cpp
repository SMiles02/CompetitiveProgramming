#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n, a[100000];

double calc(double x)
{
    double ret = 0;
    for (int i=0;i<n;++i)
        ret+=x+a[i]-min((double)a[i],x*2);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i];
    double l = 0, r = 1e9, m1, m2, x, y;
    for (int i=0;i<100;++i)
    {
        m1=l+(r-l)/3;
        m2=r-(r-l)/3;
        x=calc(m1);
        y=calc(m2);
        if (x<y)
            r=m2;
        else if (x>y)
            l=m1;
        else
        {
            l=m1;
            r=m2;
        }
    }
    cout<<fixed<<setprecision(12)<<calc(l)/n;
    return 0;
}