#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
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

void solve()
{
    int n,c=0,d=0;
    cin>>n;
    string t[n];
    for (int i=0;i<n;++i)
        cin>>t[i];
    vector<pii> x={{0,1},{1,0}},y={{0,2},{1,1},{2,0}};
    for (pii i : y)
        c+=(t[i.f][i.s]-'0');
    vector<pii> ans;
    if (c==0)
    {
        for (pii i : x)
            if ((t[i.f][i.s]=='0'))
                ans.push_back({i.f,i.s});
    }
    else if (c==3)
    {
        for (pii i : x)
            if ((t[i.f][i.s]=='1'))
                ans.push_back({i.f,i.s});
    }
    else
    {
        if (c==2)
        {
            for (pii i : x)
            {
                if (t[i.f][i.s]=='0')
                    t[i.f][i.s]='1';
                else
                    t[i.f][i.s]='0';
            }
            for (pii i : y)
            {
                if (t[i.f][i.s]=='0')
                    t[i.f][i.s]='1';
                else
                    t[i.f][i.s]='0';
            }
        }
        for (pii i : x)
            d+=(t[i.f][i.s]-'0');
        if (d==0)
        {
            for (pii i : y)
                if ((t[i.f][i.s]=='0'))
                    ans.push_back({i.f,i.s});
        }
        else if (d==1)
        {
            for (pii i : y)
                if ((t[i.f][i.s]=='1'))
                    ans.push_back({i.f,i.s});
            for (pii i : x)
                if ((t[i.f][i.s]=='0'))
                    ans.push_back({i.f,i.s});
        }
        else
        {
            for (pii i : y)
                if ((t[i.f][i.s]=='1'))
                    ans.push_back({i.f,i.s});
        }
    }
    cout<<sz(ans)<<"\n";
    for (pii i : ans)
        cout<<i.f+1<<" "<<i.s+1<<"\n";
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