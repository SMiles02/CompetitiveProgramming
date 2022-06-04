#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,k,x,sum=0;
    cin>>n>>k;
    vector<int> a;
    vector<int> b;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        a.push_back(x);
    }
    for (int i=0;i<n;++i)
    {
        cin>>x;
        b.push_back(x);
    }
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());
    for (int i=0;i<k&&a.back()<b.back();++i)
    {
        a.pop_back();
        sum+=b.back();
        b.pop_back();
    }
    for (auto i : a)
        sum+=i;
    cout<<sum<<"\n";
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