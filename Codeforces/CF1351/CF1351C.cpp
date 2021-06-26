#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    string s;
    int n,a=0,b=0;
    ll num=0;
    cin>>s;
    n=sz(s);
    map<pair<pair<int,int>,int>,int> m;
    for (int i=0;i<n;++i)
    {
        if (s[i]=='N')
        {
            if (m[{{a,b},1}])
            {
                ++num;
            }
            else
            {
                num+=5;
            }
            m[{{a,b},1}]=1;
            ++b;
            m[{{a,b},2}]=1;
        }
        if (s[i]=='S')
        {
            if (m[{{a,b},2}])
            {
                ++num;
            }
            else
            {
                num+=5;
            }
            m[{{a,b},2}]=1;
            --b;
            m[{{a,b},1}]=1;
        }
        if (s[i]=='E')
        {
            if (m[{{a,b},3}])
            {
                ++num;
            }
            else
            {
                num+=5;
            }
            m[{{a,b},3}]=1;
            ++a;
            m[{{a,b},4}]=1;
        }
        if (s[i]=='W')
        {
            if (m[{{a,b},4}])
            {
                ++num;
            }
            else
            {
                num+=5;
            }
            m[{{a,b},4}]=1;
            --a;
            m[{{a,b},3}]=1;
        }
    }
    cout<<num<<"\n";
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