#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
 
string zeroes(string k)
{
    string s="";
    for (int i=1;i<sz(k);++i)
        s+=k[i];
    return s;
}
 
bool pTen(string x)
{
    while (sz(x)>1)
    {
        if ((x.back()-'0')%10)
            return 0;
        x.pop_back();
    }
    if (x!="1")
        return 0;
    return 1;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,z=0,f=0;
    string s="",x,k;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        if (x=="0")
            z=1;
        else if (!pTen(x))
        {
            f=1;
            k=x;
        }
        else
            s+=zeroes(x);
    }
    if (z)
        cout<<0;
    else if (f)
        cout<<k<<s;
    else
        cout<<1<<s;
    return 0;
}