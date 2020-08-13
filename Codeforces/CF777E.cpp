#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
        return res * a;
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
    int n,a,b,h;
    cin>>n;
    set<int> s;
    map<int,pair<int,int>> m;
    for (int i=0;i<n;++i)
    {
        cin>>a>>b>>h;
        if (m[b].first)
            m[b]={min(a,m[b].first),h+m[b].second};
        else
            m[b]={a,h};
        s.insert(b);
    }
    map<int,ll> ans;
    stack<int> st;
    for (int i : s)
    {
        ll cur=m[i].second;
        while (sz(st))
        {
            if (st.top()>m[i].first)
            {
                cur+=ans[st.top()];
                break;
            }
            st.pop();
        }
        ans[i]=cur;
        st.push(i);
    }
    ll tot=0;
    for (int i : s)
        if (ans[i]>tot)
            tot=ans[i];
    cout<<tot;
    return 0;
}