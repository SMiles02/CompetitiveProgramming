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

int score(int n)
{
    if (n==0)
        return 2;
    if (n==1)
        return 7;
    if (n==2)
        return 2;
    if (n==3)
        return 3;
    if (n==4)
        return 3;
    if (n==5)
        return 4;
    if (n==6)
        return 2;
    if (n==7)
        return 5;
    if (n==8)
        return 1;
    if (n==9)
        return 2;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin>>s;
    cout<<score(s[0]-'0')*score(s[1]-'0');
    return 0;
}