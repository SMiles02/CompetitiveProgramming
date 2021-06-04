#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

string to_upper(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin>>s;
    bool f=0;
    deque<char> t;
    for (auto i : s)
    {
        if (i=='R')
            f^=1;
        else if (f)
            t.push_back(i);
        else
            t.push_front(i);
    }
    string ans = "!";
    if (f)
    {
        for (auto i : t)
        {
            if (i!=ans.back())
                ans.push_back(i);
            else
                ans.pop_back();
        }
    }
    else
        while (!t.empty())
        {
            if (t.back()!=ans.back())
                ans.push_back(t.back());
            else
                ans.pop_back();
            t.pop_back();
        }
    for (int i=1;i<sz(ans);++i)
        cout<<ans[i];
    return 0;
}