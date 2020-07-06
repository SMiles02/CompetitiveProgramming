#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

double pi = 3.14159265358979;

void solve()
{
    double n;
    cin>>n;
    cout<<fixed<<setprecision(12)<<cos(pi/(4*n))/sin(pi/(2*n))<<"\n";
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