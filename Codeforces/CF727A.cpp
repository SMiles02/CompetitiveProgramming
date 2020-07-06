#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int done=0,a;
vector<int> v;

void dfs(int n)
{
    if (n==a)
    {
        done=1;
        v.push_back(n);
        return;
    }
    if (n<a)
    {
        return;
    }
    if (!(n%2))
    {
        dfs(n/2);
        if (done)
        {
            v.push_back(n);
        }
        return;
    }
    if (n%10==1)
    {
        dfs((n-1)/10);
        if (done)
        {
            v.push_back(n);
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int b;
    cin>>a>>b;
    dfs(b);
    if (done)
    {
        cout<<"YES\n"<<sz(v)<<"\n";
        for (int i=0;i<sz(v);++i)
        {
            cout<<v[i]<<" ";
        }
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}