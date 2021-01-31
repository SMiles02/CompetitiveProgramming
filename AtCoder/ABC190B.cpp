#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,s,d,x,y;
    cin>>n>>s>>d;
    while (n--)
    {
        cin>>x>>y;
        if (x<s&&y>d)
        {
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
}