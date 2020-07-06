#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,maxX=0,maxY=0,h,w;
    string s;
    cin>>n;
    while (n--)
    {
        cin>>s>>h>>w;
        if (s[0]=='+')
        {
            maxX=max(maxX,min(h,w));
            maxY=max(maxY,max(h,w));
        }
        else
        {
            if (maxX<=min(h,w)&&maxY<=max(h,w))
            {
                cout<<"YES\n";
            }
            else
            {
                cout<<"NO\n";
            }
        }
    }
    return 0;
}