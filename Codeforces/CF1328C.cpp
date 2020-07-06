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
    int n,t,f;
    string s,a,b;
    cin>>t;
    while (t--)
    {
        a.clear();
        b.clear();
        f=0;
        cin>>n;
        cin>>s;
        for (int i=0;i<n;++i)
        {
            if (s[i]=='2')
            {
                if (f)
                {
                    a+='0';
                    b+='2';
                }
                else
                {
                    a+='1';
                    b+='1';
                }
            }
            else if (s[i]=='1')
            {
                if (f)
                {
                    a+='0';
                    b+='1';
                }
                else
                {
                    f=1;
                    a+='1';
                    b+='0';
                }
            }
            else
            {
                a+='0';
                b+='0';
            }
        }
        cout<<a<<"\n"<<b<<"\n";
    }
    return 0;
}