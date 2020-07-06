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
    int n,k,x,b;
    cin>>n>>k;
    string s,t;
    cin>>s;
    t=s;
    if (k==1)
    {
        b=1;
        for (int i=1;i<n;++i)
        {
            if (s[0]<s[i])
            {
                b=0;
                break;
            }
            if (s[0]>s[i])
            {
                break;
            }
        }
        if (b)
        {
            x=(s[0]-'0');
        }
        else
        {
            x=(s[0]-'0')+1;
        }
        for (int i=0;i<n;++i)
        {
            cout<<x;
        }
        return 0;
    }
    if (s[0]>s[k])
    {
        for (int i=0;i+k<n;++i)
        {
            s[i+k]=s[i];
        }
        cout<<s;
        return 0;
    }
    if (s[i]==s[k])
    {
        
    }
    cout<<s;
    return 0;
}