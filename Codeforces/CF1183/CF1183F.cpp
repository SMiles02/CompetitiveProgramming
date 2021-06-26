#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int sum(vector<int> v)
{
    int k=0;
    for (int i=0;i<sz(v);++i)
    {
        k+=v[i];
    }
    return k;
}

void solve()
{
    int n,k,isTrue,f1=0,f2=0,f3=0;
    cin>>n;
    vector<int> v;
    vector<int> chosen;
    vector<int> w;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    chosen.push_back(v.back());
    v.pop_back();
    while (sz(v)&&sz(chosen)<3)
    {
        isTrue=1;
        for (int i=0;i<sz(chosen);++i)
        {
            if (!(chosen[i]%v.back()))
            {
                isTrue=0;
                break;
            }
        }
        if (isTrue)
        {
            chosen.push_back(v.back());
        }
        else
        {
            w.push_back(v.back());
        }
        v.pop_back();
    }
    for (int i=0;i<sz(w);++i)
    {
        if (w[i]*2==chosen[0])
        {
            f1=1;
        }
        if (w[i]*3==chosen[0])
        {
            f2=1;
        }
        if (w[i]*5==chosen[0])
        {
            f3=1;
        }
    }
    if (f1&&f2&&f3)
    {
        cout<<max(chosen[0]/5+chosen[0]/3+chosen[0]/2,sum(chosen))<<"\n";
    }
    else
    {
        cout<<sum(chosen)<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin>>q;
    while (q--)
    {
        solve();
    }
    return 0;
}