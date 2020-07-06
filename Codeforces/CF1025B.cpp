#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b;
    cin>>n;
    vector<int> v;
    cin>>a>>b;
    for (int i=2;i<=sqrt(a);++i)
    {
        if (!(a%i))
        {
            v.push_back(i);
            while (!(a%i))
            {
                a/=i;
            }
        }
    }
    if (a!=1)
    {
        v.push_back(a);
    }
    for (int i=2;i<=sqrt(b);++i)
    {
        if (!(b%i))
        {
            v.push_back(i);
            while (!(b%i))
            {
                b/=i;
            }
        }
    }
    if (b!=1)
    {
        v.push_back(b);
    }
    for (int i=1;i<n;++i)
    {
        cin>>a>>b;
        for (int j=0;j<sz(v);++j)
        {
            if ((a%v[j])&&(b%v[j]))
            {
                v.erase(v.begin()+j);
                --j;
            }
        }
    }
    if (sz(v))
    {
        cout<<v[0];
    }
    else
    {
        cout<<-1;
    }
    return 0;
}