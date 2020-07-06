#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

double max(double x, double y)
{
    if (x>y)
        return x;
    return y;
}

double sq(double d)
{
    return d*d;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,r,x;
    double y;
    vector<pair<int,double>> v;
    cin>>n>>r;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        y=r;
        for (auto j : v)
            if (j.first-(2*r)<=x&&x<=j.first+(2*r))
                y=max(y,j.second+sqrt((4*r*r)-sq(j.first-x)));
        v.push_back({x,y});
    }
    for (auto i : v)
        cout<<fixed<<setprecision(7)<<i.second<<"\n";
    return 0;
}