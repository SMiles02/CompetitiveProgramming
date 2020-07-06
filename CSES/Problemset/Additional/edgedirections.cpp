#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#define gc getchar_unlocked
using namespace std;

int inp()
{
    char c=gc();
    int t=0;
    while (c==0 || c==-1 || c==' ' || c=='\n' || c=='\r')
        c=gc();
    while (c!=' ' && c!='\n' && c!=-1 && c && c!='\r')
    {
        t=t*10+c-'0';
        c=gc();
    }
    return t;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y;
    n=inp();
    n=inp();
    while (n--)
    {
        x=inp();y=inp();
        if (x<y)
            cout<<x<<" "<<y<<"\n";
        else
            cout<<y<<" "<<x<<"\n";
    }
    return 0;
}