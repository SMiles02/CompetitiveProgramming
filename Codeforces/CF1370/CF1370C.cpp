#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

bool twoPow(int n)
{
    for (int i=0;i<33;++i)
        if ((1<<i)&n)
        {
            if (i&1)
                return 1;
            else
                return 0;
        }
    return 1;
}

void solve()
{
    int n,k;
    bool b;
    cin>>n;
    if (n==1)
    {
        cout<<"FastestFinger\n";
        return;
    }
    if (n&1)
    {
        cout<<"Ashishgup\n";
        return;
    }
    vector<int> v;
    vector<int> w;
    vector<bool> result;
    for (int i=1;i*i<=n;++i)
        if (!(n%i))
        {
            if (i*i==n)
                v.push_back(i);
            else
            {
                v.push_back(i);
                w.push_back(n/i);
            }
        }
    for (int i=sz(w)-1;i+1;--i)
        v.push_back(w[i]);
    result.push_back(0);
    result.push_back(1);
    k=sz(v);
    for (int i=2;i<k;++i)
    {
        if (v[i]&1)
        {
            result.push_back(1);
            continue;
        }
        b=0;
        for (int j=0;j<i;++j)
            if (!(v[i]%v[j]))
                if ((v[i]/v[j])&1)
                    if (!result[j])
                    {
                        b=1;
                        break;
                    }
        result.push_back(b);
    }
    /**for (int i : v)
        cout<<i<<" ";
    cout<<"\n";
    for (bool i : result)
        cout<<i<<" ";**/
    if (result.back())
        cout<<"Ashishgup\n";
    else
        cout<<"FastestFinger\n";
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