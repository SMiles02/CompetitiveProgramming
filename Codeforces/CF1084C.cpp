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
    string s;
    cin>>s;
    int n=s.size(),cur=0;
    ll ans=1;
    for (int i=0;i<n;++i)
    {
        if (s[i]=='a')
        {
            ++cur;
        }
        else if (s[i]=='b')
        {
            ans*=(cur+1);
            ans%=MOD;
            cur=0;
        }
    }
    ans*=(cur+1);
    --ans;
    ans%=MOD;
    cout<<ans;
    return 0;
}