#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
        return 1;
    int res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
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
    int n,m,q,x;
    cin>>n>>m;
    string s;
    map<int,string> a;
    map<int,string> b;
    for (int i=1;i<n;++i)
    {
        cin>>s;
        a[i]=s;
    }
    cin>>s;
    a[0]=s;
    for (int i=1;i<m;++i)
    {
        cin>>s;
        b[i]=s;
    }
    cin>>s;
    b[0]=s;
    cin>>q;
    while (q--)
    {
        cin>>x;
        cout<<a[x%n]<<b[x%m]<<"\n";
    }
    return 0;
}