#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
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
    int n,m,ans=0,total=0;
    double mini;
    cin>>n>>m;
    double a[n];
    mini=1;
    mini/=(4*m);
    //cout<<mini<<"\n";
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        total+=a[i];
    }
    for (int i=0;i<n;++i)
    {
        a[i]/=total;
        if (a[i]>=mini)
        {
            ++ans;
        }
    }
    if (ans>=m)
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
    return 0;
}