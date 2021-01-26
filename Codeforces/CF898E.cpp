#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int sq(int x)
{
    return x*x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,s=0;
    cin>>n;
    int a[n];
    vector<int> v,w;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        if (sq(sqrt(a[i]))==a[i])
        {
            ++s;
            if (a[i]==0)
                w.push_back(2);
            else
                w.push_back(1);
        }
        else
            v.push_back(min(a[i]-sq(sqrt(a[i])),sq(sqrt(a[i])+1)-a[i]));
    }
    ll ans=0;
    sort(v.rbegin(), v.rend());
    sort(w.rbegin(), w.rend());
    while (s>n/2)
    {
        ans+=w.back();
        w.pop_back();
        --s;
    }
    while (s<n/2)
    {
        ans+=v.back();
        v.pop_back();
        ++s;
    }
    cout<<ans;
    return 0;
}