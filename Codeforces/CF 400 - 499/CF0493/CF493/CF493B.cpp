#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,last;
    ll a=0;
    cin>>n;
    vector<int> v;
    vector<int> w;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        if (k>0)
        {
            v.push_back(k);
            last=0;
        }
        else
        {
            w.push_back(-k);
            last=1;
        }
        a+=k;
    }
    if (a>0)
    {
        cout<<"first";
        return 0;
    }
    if (a<0)
    {
        cout<<"second";
        return 0;
    }
    k=min(sz(v),sz(w));
    for (int i=0;i<k;++i)
    {
        if (v[i]>w[i])
        {
            cout<<"first";
            return 0;
        }
        if (v[i]<w[i])
        {
            cout<<"second";
            return 0;
        }
    }
    if (sz(v)>k)
    {
        cout<<"first";
        return 0;
    }
    if (sz(w)>k||last)
    {
        cout<<"second";
        return 0;
    }
    cout<<"first";
    return 0;
}