#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,k;
map<int,int> m;
vector<int> v;

void solve()
{
    cin>>n;
    while (n--)
    {
        cin>>k;
        while (!(k%2)&&!m[k])
        {
            v.push_back(k);
            m[k]=1;
            k/=2;
        }
    }
    cout<<sz(v)<<"\n";
    v.clear();
    m.clear();
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}