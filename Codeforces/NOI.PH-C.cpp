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
    int t,n,i,a,b,c;
    string s;
    cin>>t;
    while (t--)
    {
        a=0;b=0;c=0;i=0;
        cin>>n>>s;
        while (i<n)
        {
            if (s[i]=='T')
            {
                ++a;
                i+=2;
            }
            else if (s[i]=='s')
            {
                ++b;
                i+=2;
            }
            else
            {
                ++c;
                i+=3;
            }
        }
        cout<<a<<" "<<b<<" "<<c<<"\n";
    }
    return 0;
}