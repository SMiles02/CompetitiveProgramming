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
    int n,a,b;
    string s,t;
    cin>>n;
    cin>>s;
    cin>>t;
    map<pair<char,char>,int> m;
    for (int i=0;i<n*2;++i)
    {
        ++m[{s[i],t[i]}];
    }
    for (int i=0;i<n;++i)
    {
        if (m[{'1','1'}])
        {
            --m[{'1','1'}];
            a=1;
        }
        else if (m[{'1','0'}])
        {
            --m[{'1','0'}];
            a=1;
        }
        else if (m[{'0','1'}])
        {
            --m[{'0','1'}];
            a=0;
        }
        else
        {
            --m[{'0','0'}];
            a=0;
        }
        if (m[{'1','1'}])
        {
            --m[{'1','1'}];
            b=1;
        }
        else if (m[{'0','1'}])
        {
            --m[{'0','1'}];
            b=1;
        }
        else if (m[{'1','0'}])
        {
            --m[{'1','0'}];
            b=0;
        }
        else
        {
            --m[{'0','0'}];
            b=0;
        }
        if (a>b)
        {
            cout<<"First";
            return 0;
        }
        if (b>a)
        {
            cout<<"Second";
            return 0;
        }
    }
    cout<<"Draw";
    return 0;
}