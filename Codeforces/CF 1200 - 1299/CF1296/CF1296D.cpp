#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,a,b,k,ans=0;
    cin>>n>>a>>b>>k;
    int h[n];
    vector<int> v;
    for (int i=0;i<n;++i)
    {
        cin>>h[i];
        if (h[i]%(a+b))
        {
            h[i]%=(a+b);
        }
        else if (h[i]>a+b)
        {
            h[i]=a+b;
        }
        //cout<<h[i]<<" ";
        if (a>=h[i])
        {
            ++ans;
        }
        else
        {
            h[i]-=a;
            v.push_back((h[i]-1)/a+1);
        }
    }
    /**cout<<"\n"<<ans<<"\n";
    for (int i=0;i<sz(v);++i)
    {
        cout<<v[i]<<" ";
    }**/
    sort(v.rbegin(), v.rend());
    while (sz(v)&&v.back()<=k)
    {
        k-=v.back();
        ++ans;
        v.pop_back();
    }
    cout<<ans;
    return 0;
}