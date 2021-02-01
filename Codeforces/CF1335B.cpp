#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    string alpha="abcdefghijklmnopqrstuvwxyz";
    int n,a,b,cur=0;
    cin>>n>>a>>b;
    while (1)
    {
        for (int i=0;i<b;++i)
        {
            cout<<alpha[i];
            ++cur;
            if (cur==n)
            {
                cout<<"\n";
                return;
            }
        }
        for (int i=b;i<a;++i)
        {
            cout<<alpha[b-1];
            ++cur;
            if (cur==n)
            {
                cout<<"\n";
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}