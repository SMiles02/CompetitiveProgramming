#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int counter(vector<int> v, vector<int> w)
{
    int c=0;
    for (int i=0;i<21;++i)
    {
        if (v[i]!=w[i])
        {
            ++c;
        }
    }
    return c;
}

vector<int> builder(int n)
{
    vector<int> v;
    for (int i=0;i<21;++i)
    {
        v.push_back(n%2);
        n/=2;
    }
    return v;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,t,ans=0;
    vector<vector<int>> vS;
    vector<int> v;
    cin>>n>>m>>k;
    for (int i=0;i<m;++i)
    {
        cin>>t;
        vS.push_back(builder(t));
    }
    cin>>t;
    v=builder(t);
    for (int i=0;i<m;++i)
    {
        if (counter(vS[i],v)<=k)
        {
            ++ans;
        }
    }
    cout<<ans;
    return 0;
}