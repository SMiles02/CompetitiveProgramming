#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll binpow(ll a, ll b) {
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
    int n,m,c;
    cin>>n>>m;
    if (n==1&&m>2)
    {
        cout<<"1\n1 "<<m<<" 1 1\n";
        for (int i=1;i<=m;++i)
            cout<<"1 "<<i<<"\n";
        cout<<"1 1\n";
        return 0;
    }
    if (m==1&&n>2)
    {
        cout<<"1\n"<<n<<" 1 1 1\n";
        for (int i=1;i<=n;++i)
            cout<<i<<" 1"<<"\n";
        cout<<"1 1\n";
        return 0;
    }
    if (n%2&&m%2)
        cout<<"1\n"<<n<<" 1 1 1\n";
    else
        cout<<"0\n";
    for (int i=1;i<=m;++i)
        cout<<"1 "<<i<<"\n";
    for (int i=2;i<=n;++i)
        cout<<i<<" "<<m<<"\n";
    
    if (n%2)
    {
        c=n;
        for (int i=m-1;i>0;--i)
        {
            if (c==n)
                for (int j=n;j>1;--j)
                    cout<<j<<" "<<i<<"\n";
            else
                for (int j=2;j<=n;++j)
                    cout<<j<<" "<<i<<"\n";
            c=n+2-c;
        }
    }
    else
    {
        c=m-1;
        for (int i=n;i>1;--i)
        {
            if (c==m-1)
                for (int j=m-1;j>0;--j)
                    cout<<i<<" "<<j<<"\n";
            else
                for (int j=1;j<m;++j)
                    cout<<i<<" "<<j<<"\n";
            c=m-c;
        }
    }
    cout<<"1 1\n";
    return 0;
}