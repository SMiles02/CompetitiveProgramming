#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    string s;
    cin>>s;
    n=sz(s);
    map<char,int> m;
    for (int i=0;i<n;++i)
    {
        ++m[s[i]];
    }
    if (m['A'])
    {
        cout<<'A';
    }
    if (m['K'])
    {
        cout<<'K';
    }
    if (m['Q'])
    {
        cout<<'Q';
    }
    if (m['J'])
    {
        cout<<'J';
    }
    if (m['0'])
    {
        cout<<10;
    }
    if (m['9'])
    {
        cout<<9;
    }
    if (m['8'])
    {
        cout<<8;
    }
    if (m['7'])
    {
        cout<<7;
    }
    if (m['6'])
    {
        cout<<6;
    }
    if (m['5'])
    {
        cout<<5;
    }
    if (m['4'])
    {
        cout<<4;
    }
    if (m['3'])
    {
        cout<<3;
    }
    if (m['2'])
    {
        cout<<2;
    }
    return 0;
}