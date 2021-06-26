#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,s=0,h=0,x,y;
    string a,b;
    cin>>n;
    while (n--)
    {
        cin>>a>>b;
        if (b=="soft")
        {
            ++s;
        }
        else
        {
            ++h;
        }
    }
    for (int i=1;i<1000;++i)
    {
        x=i*i;
        y=x/2;
        x-=y;
        if (max(s,h)<=x&&min(s,h)<=y)
        {
            cout<<i;
            return 0;
        }
    }
    return 0;
}