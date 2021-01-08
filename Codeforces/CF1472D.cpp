#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

void solve()
{
    int n,k;
    cin>>n;
    ll a=0,b=0;
    vector<int> o={0},e={0};
    for (int i=0;i<n;++i)
    {
        cin>>k;
        if (k&1)
            o.push_back(k);
        else
            e.push_back(k);
    }
    sort(o.begin(), o.end());
    sort(e.begin(), e.end());
    for (int i=0;i<n;++i)
    {
        if (i&1)
        {
            if (sz(o)==1)
                e.pop_back();
            else if (sz(e)==1)
            {
                b+=o.back();
                o.pop_back();
            }
            //else if (o.back()-o[sz(o)-2]>=e.back()-e[sz(e)-2])
            else if (o.back()>e.back())
            {
                b+=o.back();
                o.pop_back();
            }
            else
                e.pop_back();
        }
        else
        {
            if (sz(e)==1)
                o.pop_back();
            else if (sz(o)==1)
            {
                a+=e.back();
                e.pop_back();
            }
            //else if (o.back()-o[sz(o)-2]>=e.back()-e[sz(e)-2])
            else if (o.back()<e.back())
            {
                a+=e.back();
                e.pop_back();
            }
            else
                o.pop_back();
        }
    }
    if (a>b)
        cout<<"Alice\n";
    else if (b>a)
        cout<<"Bob\n";
    else
        cout<<"Tie\n";
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