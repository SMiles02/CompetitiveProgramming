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
    int n;
    bool x;
    cin>>n;
    int a[n];
    stack<int> s,t;
    vector<string> ans;
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=n-1;i+1;--i)
        s.push(a[i]);
    sort(a,a+n,greater<int>());
    for (int i=0;i<n;++i)
    {
        x=0;
        while (sz(s)>i)
        {
            if (s.top()==a[i]&&x==0)
            {
                ans.push_back("UZMI L L");
                x=1;
                s.pop();
            }
            else if (x)
            {
                ans.push_back("UZMI D L");
                ans.push_back("STAVI D D");
                t.push(s.top());
                s.pop();
            }
            else
            {
                ans.push_back("UZMI L L");
                ans.push_back("STAVI L D");
                t.push(s.top());
                s.pop();
            }
        }
        ans.push_back("STAVI L L");
        s.push(a[i]);
        while (sz(t))
        {
            ans.push_back("UZMI L D");
            ans.push_back("STAVI L L");
            s.push(t.top());
            t.pop();
        }
    }
    cout<<sz(ans)<<"\n";
    for (string i : ans)
        cout<<i<<"\n";
    return 0;
}