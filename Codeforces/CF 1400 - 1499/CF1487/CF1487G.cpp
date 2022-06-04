#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mod = 1e9+7, mn = 26;
int n;
set<pair<int,vector<int>>> s[401];
map<pair<int,vector<int>>,int> m[401];
string alpha = "abcdefghijklmnopqrstuvwxyz";

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

int f(int k, vector<int> v, int x, int y)
{
    if (k==n)
    {
        m[k][{c*26+d,v}]=1;
        s[k].insert({c*26+d,v});
        return 1;
    }
    int ans=0;
    for (int i=0;i<26;++i)
        if (alpha[i]!=c&&v[i]>0)
        {
            --v[i];
            if (s[k+1].find({{c,d},v})==s[k+1].end())
                ans=add(ans,f(k+1,v,));
            else
                ans=add(ans,m[k+1][{{c,d},v}]);
        }
    s[k].insert({{c,d},v});
    return m[k][{{c,d},v}]=ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    vector<int> v(26);
    for (int i=0;i<26;++i)
        cin>>v[i];
    cout<<f(0, v, 27*27);
    return 0;
}