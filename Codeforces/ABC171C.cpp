#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string a="zabcdefghijklmnopqrstuvwxyz",s="";

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin>>n;
    while (n)
    {
        s+=a[n%26];
        if (!(n%26))
            --n;
        n/=26;
    }
    for (int i=sz(s)-1;i+1;--i)
        cout<<s[i];
    return 0;
}