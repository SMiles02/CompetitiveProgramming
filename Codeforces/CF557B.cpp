#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    double w;
    cin>>n>>w;
    double a[2*n];
    for (int i=0;i<2*n;++i)
    {
        cin>>a[i];
    }
    sort(a,a+(2*n));
    cout<<setprecision(10)<<min(min(a[0],a[n]/2)*3*n,w);
    return 0;
}