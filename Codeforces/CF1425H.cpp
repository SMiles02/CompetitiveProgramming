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
    int n,a[4];
    bool ans[4];
    cin>>n;
    while (n--)
    {
        for (int i=0;i<4;++i)
            cin>>a[i];
        if ((a[0]+a[1])&1)
        {
            if (a[0]||a[3])
                ans[0]=1;
            else
                ans[0]=0;
            if (a[1]||a[2])
                ans[1]=1;
            else
                ans[1]=0;
            ans[2]=0;
            ans[3]=0;
        }
        else
        {
            if (a[0]||a[3])
                ans[3]=1;
            else
                ans[3]=0;
            if (a[1]||a[2])
                ans[2]=1;
            else
                ans[2]=0;
            ans[0]=0;
            ans[1]=0;
        }
        for (int i=0;i<4;++i)
        {
            if (ans[i])
                cout<<"Ya ";
            else
                cout<<"Tidak ";
        }
        cout<<"\n";
    }
    return 0;
}