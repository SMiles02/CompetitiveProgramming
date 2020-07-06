#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define MOD 1000000007
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
    ll fib[100001];
    fib[1]=1;
    fib[2]=2;
    for (int i=3;i<100001;++i)
    {
        fib[i]=fib[i-1]+fib[i-2];
        fib[i]%=MOD;
    }
    int n,adder;
    ll ans=1;
    string s;
    cin>>s;
    n=sz(s);
    for (int i=0;i<n;++i)
    {
        if (s[i]=='w'||s[i]=='m')
        {
            cout<<0;
            return 0;
        }
        if (s[i]=='n'||s[i]=='u')
        {
            for (adder=0;i+adder<n;++adder)
            {
                if (s[i]!=s[i+adder])
                {
                    break;
                }
            }
            i+=adder-1;
            ans*=fib[adder];
            //cout<<ans<<"\n";
            ans%=MOD;
        }
    }
    cout<<ans;
    return 0;
}