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

const int INF = 1e6;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,c,d,ans=0,b,p,l,r,m;
    cin>>n>>c>>d;
    char ch;
    vector<array<int,2>> C1,C2,D1,D2;
    while (n--)
    {
        cin>>b>>p>>ch;
        if (ch=='C')
        {
            if (p<=c)
            {
                C1.push_back({b,p});
                C2.push_back({p,b});
            }
        }
        else if (p<=d)
            {
                D1.push_back({b,p});
                D2.push_back({p,b});
            }
    }
    sort(C1.begin(), C1.end());
    sort(C2.begin(), C2.end());
    sort(D1.begin(), D1.end());
    sort(D2.begin(), D2.end());
    vector<array<int,2>> C3=C2,D3=D2;
    if (sz(C1)&&sz(D1))
        ans=C1.back()[0]+D1.back()[0];
    for (int i=1;i<sz(C2);++i)
        C2[i][1]=max(C2[i][1],C2[i-1][1]);
    for (int i=1;i<sz(D2);++i)
        D2[i][1]=max(D2[i][1],D2[i-1][1]);
    //cout<<ans<<"\n";
    for (int i=1;i<sz(C2);++i)
    {
        if (C2[0][0]>c-C2[i][0])
            continue;
        l=0;r=i-1;
        while (l^r)
        {
            m=l+(r-l)/2+1;
            if (C2[m][0]>c-C2[i][0])
                r=m-1;
            else
                l=m;
        }
        ans=max(ans,C3[i][1]+C2[l][1]);
    }
    for (int i=1;i<sz(D2);++i)
    {
        if (D2[0][0]>d-D2[i][0])
            continue;
        l=0;r=i-1;
        while (l^r)
        {
            m=l+(r-l)/2+1;
            if (D2[m][0]>d-D2[i][0])
                r=m-1;
            else
                l=m;
        }
        ans=max(ans,D3[i][1]+D2[l][1]);
    }
    cout<<ans;
    return 0;
}