#include <bits/stdc++.h>
using namespace std;

double sq(double d)
{
    return d*d;
}

void solve()
{
    int n,x,y;
    cin>>n;
    vector<int> v,w;
    double ans = 0;
    for (int i=0;i<2*n;++i)
    {
        cin>>x>>y;
        if (x==0)
            v.push_back(abs(y));
        else
            w.push_back(abs(x));
    }
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    for (int i=0;i<n;++i)
        ans+=sqrt(sq(v[i])+sq(w[i]));
    cout<<fixed<<setprecision(15)<<ans<<"\n";
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