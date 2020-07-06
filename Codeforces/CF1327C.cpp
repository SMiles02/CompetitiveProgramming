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
    int n,m,k,a,b;
    cin>>n>>m>>k;
    for (int i=0;i<2*k;++i)
    {
        cin>>a>>b;
    }
    cout<<n+m-3+n*m<<"\n";
    for (int i=1;i<m;++i)
    {
        cout<<"L";
    }
    for (int i=1;i<n;++i)
    {
        cout<<"U";
    }
    for (int i=0;i<n;++i)
    {
        if (i%2)
        {
            for (int j=1;j<m;++j)
            {
                cout<<"L";
            }
        }
        else
        {
            for (int j=1;j<m;++j)
            {
                cout<<"R";
            }
        }
        if (i+1<n)
        {
            cout<<"D";
        }
    }
    return 0;
}